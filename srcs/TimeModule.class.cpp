#include "TimeModule.class.hpp"
#include <algorithm>

TimeModule::TimeModule(void) {
	this->_infos["date"] = this->_date();
}

TimeModule::TimeModule(TimeModule const &) {}

void			TimeModule::refresh(void) {
	TimeModule::t_infos::iterator	it;

	for (it = this->_infos.begin(); it != this->_infos.end(); ++it) {
		this->refresh(it->first);
	}
}

void			TimeModule::refresh(std::string const & what) {
	t_functions		tabptr[SIZE_TAB_TIME] = {
		{ "date" , &TimeModule::_date }
	};

	for (int i = 0 ; i < SIZE_TAB_TIME ; i++) {
		if (tabptr[i].what == what)
			this->_infos[what] = (this->*(tabptr[i].funptr))();
	}
}

std::string		TimeModule::_date(void) {
	return getInfos("date");
}

TimeModule::~TimeModule(void) {}

TimeModule const		&TimeModule::operator=(TimeModule const &) { return (*this); }

TimeModule::t_infos const		&TimeModule::infos(void) const { return (this->_infos); }
