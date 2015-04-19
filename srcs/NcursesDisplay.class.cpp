#include "NcursesDisplay.class.hpp"
#include "CPUModule.class.hpp"
#include "OSModule.class.hpp"
#include "MemoryModule.class.hpp"
#include "HostUsernameModule.class.hpp"
#include "TimeModule.class.hpp"

NcursesDisplay::NcursesDisplay(void) {
	this->_modules["cpu"] = new CPUModule;
	this->_modules["os"] = new OSModule;
	this->_modules["ram"] = new MemoryModule;
	this->_modules["host"] = new HostUsernameModule;
	this->_modules["time"] = new TimeModule;
}

NcursesDisplay::NcursesDisplay(NcursesDisplay const &) {}

void							NcursesDisplay::_deleteModule(std::pair<std::string, IMonitorModule *> mod) {
	delete mod.second;
}

std::string const				&NcursesDisplay::_getData(std::string const & module, std::string const & value) const {
	return (this->_modules.find(module)->second->infos()).find(value)->second;
}

void							NcursesDisplay::display(void) const {
	std::cout << this->_getData("cpu", "nbCPU") << std::endl;
	std::cout << this->_getData("cpu", "typeCPU") << std::endl;

	std::cout << this->_getData("os", "osType") << std::endl;
	std::cout << this->_getData("os", "productName") << std::endl;
	std::cout << this->_getData("os", "productVersion") << std::endl;

	std::cout << this->_getData("ram", "total") << std::endl;

	std::cout << this->_getData("host", "hostName") << std::endl;

	std::cout << this->_getData("time", "date") << std::endl;
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
