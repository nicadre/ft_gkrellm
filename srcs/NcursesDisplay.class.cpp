#include "NcursesDisplay.class.hpp"
#include "CPUModule.class.hpp"

NcursesDisplay::NcursesDisplay(void) {
	this->_modules["cpu"] = new CPUModule;
}

NcursesDisplay::NcursesDisplay(NcursesDisplay const &) {}

void							NcursesDisplay::_deleteModule(std::pair<std::string, IMonitorModule *> mod) {
	delete mod.second;
}

std::string const				&NcursesDisplay::_giveMePlease(std::string const & module, std::string const & value) const {
	return (this->_modules.find(module)->second->infos()).find(value)->second;
}

void							NcursesDisplay::display(void) const {
	std::cout << this->_giveMePlease("cpu", "nbCPU") << std::endl;
}

NcursesDisplay::~NcursesDisplay(void) {
	for_each(this->_modules.begin(), this->_modules.end(), this->_deleteModule);
}

NcursesDisplay const			&NcursesDisplay::operator=(NcursesDisplay const &) { return (*this); }

IMonitorDisplay::t_infos const	&NcursesDisplay::modules(void) const { return (this->_modules); }
int								NcursesDisplay::width(void) const { return (this->_width); }
int								NcursesDisplay::height(void) const { return (this->_height); }

void							NcursesDisplay::modules(IMonitorDisplay::t_infos const & modules) { this->_modules = modules; }
void							NcursesDisplay::width(int width) { this->_width = width; }
void							NcursesDisplay::height(int height) { this->_height = height; }
