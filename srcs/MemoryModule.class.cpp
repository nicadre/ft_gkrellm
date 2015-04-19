#include "MemoryModule.class.hpp"
#include <algorithm>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <stdint.h>

MemoryModule::MemoryModule(void) {
	this->_infos["total"] = this->_total();
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
		{ "total" , &MemoryModule::_total }
	};

	for (int i = 0 ; i < SIZE_TAB_MEMORY ; i++) {
		if (tabptr[i].what == what)
			this->_infos[what] = (this->*(tabptr[i].funptr))();
	}
}

std::string		MemoryModule::_total(void) {
	/* Hmmm maybe not */
	int		mib[2];
	int64_t	physical_memory;
	size_t	length;

	mib[0] = CTL_HW;
	mib[1] = HW_MEMSIZE;
	length = sizeof(8);
	sysctl(mib, 2, &physical_memory, &length, NULL, 0);
	return (std::to_string(physical_memory));
}

MemoryModule::~MemoryModule(void) {}

MemoryModule const		&MemoryModule::operator=(MemoryModule const &) { return (*this); }

MemoryModule::t_infos const		&MemoryModule::infos(void) const { return (this->_infos); }
