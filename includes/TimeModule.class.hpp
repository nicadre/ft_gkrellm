#ifndef		TIMEMODULE_CLASS_HPP
# define	TIMEMODULE_CLASS_HPP

# include "IMonitorModule.interface.hpp"
# include <iostream>
# include <map>

#define SIZE_TAB_TIME 2

class TimeModule : public IMonitorModule {
private:
	IMonitorModule::t_infos	_infos;

	std::string				_date(void);

	TimeModule(TimeModule const &);

	TimeModule const			&operator=(TimeModule const &);

public:
	TimeModule(void);

	void				refresh(void);
	void				refresh(std::string const & what);

	virtual ~TimeModule(void);

	TimeModule::t_infos const			&infos(void) const;

	typedef struct		s_functions {
		std::string		what;
		std::string		(TimeModule::*funptr)(void);
	}					t_functions;
};

#endif //	TIMEMODULE_CLASS_HPP
