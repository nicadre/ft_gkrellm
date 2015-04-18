#include "CPUModule.class.hpp"

CPUModule::CPUModule(void) {}

CPUModule::CPUModule(CPUModule const &) {}



CPUModule::~CPUModule(void) {}

CPUModule const						&CPUModule::operator=(CPUModule const &) { return (*this); }

std::map<std::string, std::string>	const &CPUModule::infos(void) const { return (this->_infos); }
