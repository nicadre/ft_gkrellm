#ifndef		OSMODULE_CLASS_HPP
# define	OSMODULE_CLASS_HPP

# include "IMonitorModule.interface.hpp"
# include <iostream>
# include <map>

#define SIZE_TAB_OS 0

class OSModule : public IMonitorModule {
private:
	IMonitorModule::t_infos	_infos;

	OSModule(OSModule const &);

	OSModule const			&operator=(OSModule const &);

public:
	OSModule(void);

	void				refresh(void);
	void				refresh(std::string const & what);

	virtual ~OSModule(void);

	OSModule::t_infos const			&infos(void) const;

	typedef struct		s_functions {
		std::string		what;
		std::string		(OSModule::*funptr)(void);
	}					t_functions;
};

#endif //	OSMODULE_CLASS_HPP
