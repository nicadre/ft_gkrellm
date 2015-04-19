#include "HostUsernameModule.class.hpp"
#include <algorithm>

HostUsernameModule::HostUsernameModule(void) {
	this->_infos["hostName"] = this->_hostName();
}

HostUsernameModule::HostUsernameModule(HostUsernameModule const &) {}

void			HostUsernameModule::refresh(void) {
	HostUsernameModule::t_infos::iterator	it;

	for (it = this->_infos.begin(); it != this->_infos.end(); ++it) {
		this->refresh(it->first);
	}
}

void			HostUsernameModule::refresh(std::string const & what) {
	t_functions		tabptr[SIZE_TAB_HOSTUSER] = {
		{ "hostName" , &HostUsernameModule::_hostName}
	};

	for (int i = 0 ; i < SIZE_TAB_HOSTUSER ; i++) {
		if (tabptr[i].what == what)
			this->_infos[what] = (this->*(tabptr[i].funptr))();
	}
}

std::string		HostUsernameModule::_hostName(void) {
	return getInfos("sysctl -n kern.hostname");
}

HostUsernameModule::~HostUsernameModule(void) {}

HostUsernameModule const		&HostUsernameModule::operator=(HostUsernameModule const &) { return (*this); }

HostUsernameModule::t_infos const		&HostUsernameModule::infos(void) const { return (this->_infos); }
