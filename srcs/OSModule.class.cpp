#include "OSModule.class.hpp"
#include <algorithm>

OSModule::OSModule(void) {
	this->_infos["osType"] = this->_osType();
	this->_infos["productName"] = this->_osType();
	this->_infos["productVersion"] = this->_osType();
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
		{ "osType" , &OSModule::_osType },
		{ "productName" , &OSModule::_productName },
		{ "productVersion" , &OSModule::_productVersion }
	};

	for (int i = 0 ; i < SIZE_TAB_OS ; i++) {
		if (tabptr[i].what == what)
			this->_infos[what] = (this->*(tabptr[i].funptr))();
	}
}

std::string		OSModule::_osType(void) {
	return getInfos("sysctl -n kern.ostype");
}

std::string		OSModule::_productName(void) {
	return (getInfos("sw_vers | grep ProductName: | sed \"s/ProductName:	//\""));
}

std::string		OSModule::_productVersion(void) {
	return (getInfos("sw_vers | grep ProductVersion: | sed \"s/ProductVersion:	//\""));
}

OSModule::~OSModule(void) {}

OSModule const		&OSModule::operator=(OSModule const &) { return (*this); }

OSModule::t_infos const		&OSModule::infos(void) const { return (this->_infos); }
