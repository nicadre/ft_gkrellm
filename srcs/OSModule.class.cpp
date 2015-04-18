#include "OSModule.class.hpp"
#include <algorithm>

OSModule::OSModule(void) {
}

OSModule::OSModule(OSModule const &) {}

void			OSModule::refresh(void) {
	OSModule::t_infos::iterator	it;

	for (it = this->_infos.begin(); it != this->_infos.end(); ++it) {
		this->refresh(it->first);
	}
}

void			OSModule::refresh(std::string const & what) {
	t_functions		tabptr[SIZE_TAB_OS] = {
	};

	for (int i = 0 ; i < SIZE_TAB_OS ; i++) {
		if (tabptr[i].what == what)
			this->_infos[what] = (this->*(tabptr[i].funptr))();
	}
}

OSModule::~OSModule(void) {}

OSModule const		&OSModule::operator=(OSModule const &) { return (*this); }

OSModule::t_infos const		&OSModule::infos(void) const { return (this->_infos); }
