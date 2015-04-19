#include "NcursesDisplay.class.hpp"


NcursesDisplay::NcursesDisplay(void) {

}

NcursesDisplay::NcursesDisplay(NcursesDisplay const & src) {
	*this = src;
}


NcursesDisplay::~NcursesDisplay(void) {

}


NcursesDisplay const			&NcursesDisplay::operator=(NcursesDisplay const & rhs) {

	return (*this);
}
void			NcursesDisplay::modules(std::map<std::string, IMonitorModule> modules) { this->_modules = modules; }
void			NcursesDisplay::width(int width) { this->_width = width; }
void			NcursesDisplay::height(int height) { this->_height = height; }
