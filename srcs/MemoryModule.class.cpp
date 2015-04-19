#include "MemoryModule.class.hpp"
#include <algorithm>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <stdint.h>

#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>

MemoryModule::MemoryModule(void) {
	this->_infos["total"] = this->_total();
	this->_infos["used"] = this->_used();
}

MemoryModule::MemoryModule(MemoryModule const &) {}

void			MemoryModule::refresh(void) {
	MemoryModule::t_infos::iterator	it;

	for (it = this->_infos.begin(); it != this->_infos.end(); ++it) {
		this->refresh(it->first);
	}
}

void			MemoryModule::refresh(std::string const & what) {
	t_functions		tabptr[SIZE_TAB_MEMORY] = {
		{ "total" , &MemoryModule::_total },
		{ "used" , &MemoryModule::_used }
	};

	for (int i = 0 ; i < SIZE_TAB_MEMORY ; i++) {
		if (tabptr[i].what == what)
			this->_infos[what] = (this->*(tabptr[i].funptr))();
	}
}

std::string		MemoryModule::_total(void) {
	int64_t	physical_memory;
	size_t	length;

	length = sizeof(int64_t);
	sysctlbyname("hw.memsize", &physical_memory, &length, NULL, 0);
	return (std::to_string(physical_memory / 1024 / 1024) + " mo");
}

std::string		MemoryModule::_used(void) {
	vm_size_t page_size;
    mach_port_t mach_port;
    mach_msg_type_number_t count;
    vm_statistics64_data_t vm_stats;

	long long used_memory = 0;
	long long free_memory = 0;

    mach_port = mach_host_self();
    count = sizeof(vm_stats) / sizeof(natural_t);
    if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
        KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
										  (host_info64_t)&vm_stats, &count))
    {
        free_memory = (int64_t)vm_stats.free_count * (int64_t)page_size;

         used_memory = ((int64_t)vm_stats.active_count +
                                  (int64_t)vm_stats.inactive_count +
                                  (int64_t)vm_stats.wire_count) *  (int64_t)page_size;

	}
	return (std::to_string((used_memory + free_memory) / 1024 / 1024) + " mo");
}

MemoryModule::~MemoryModule(void) {}

MemoryModule const		&MemoryModule::operator=(MemoryModule const &) { return (*this); }

MemoryModule::t_infos const		&MemoryModule::infos(void) const { return (this->_infos); }
