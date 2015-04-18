#include "CPUModule.class.hpp"
#include <algorithm>

CPUModule::CPUModule(void) {
	this->_infos["nbCPU"] = this->_nbCPU();
	this->_infos["typeCPU"] = this->_typeCPU();
}

CPUModule::CPUModule(CPUModule const &) {}

void			CPUModule::refresh(void) {
	CPUModule::t_infos::iterator	it;

	for (it = this->_infos.begin(); it != this->_infos.end(); ++it) {
		this->refresh(it->first);
	}
}

void			CPUModule::refresh(std::string const & what) {
	t_functions		tabptr[SIZE_TAB_CPU] = {
		{ "nbCPU" , &CPUModule::_nbCPU },
		{ "typeCPU" , &CPUModule::_typeCPU }
	};

	for (int i = 0 ; i < SIZE_TAB_CPU ; i++) {
		if (tabptr[i].what == what)
			this->_infos[what] = (this->*(tabptr[i].funptr))();
	}
}

std::string		CPUModule::_nbCPU(void) {
	return getInfos("sysctl -n hw.ncpu");
}

std::string		CPUModule::_typeCPU(void) {
	return getInfos("sysctl -n machdep.cpu.brand_string");
}

CPUModule::~CPUModule(void) {}

CPUModule const		&CPUModule::operator=(CPUModule const &) { return (*this); }

CPUModule::t_infos const		&CPUModule::infos(void) const { return (this->_infos); }
