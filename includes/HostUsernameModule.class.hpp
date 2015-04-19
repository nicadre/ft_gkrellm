#ifndef		HOSTUSERNAMEMODULE_CLASS_HPP
# define	HOSTUSERNAMEMODULE_CLASS_HPP

# include "IMonitorModule.interface.hpp"
# include <iostream>
# include <map>

#define SIZE_TAB_HOSTUSER 1

class HostUsernameModule : public IMonitorModule {
private:
	IMonitorModule::t_infos	_infos;

	std::string				_hostName(void);

	HostUsernameModule(HostUsernameModule const &);

	HostUsernameModule const			&operator=(HostUsernameModule const &);

public:
	HostUsernameModule(void);

	void				refresh(void);
	void				refresh(std::string const & what);

	virtual ~HostUsernameModule(void);

	HostUsernameModule::t_infos const			&infos(void) const;

	typedef struct		s_functions {
		std::string		what;
		std::string		(HostUsernameModule::*funptr)(void);
	}					t_functions;
};

#endif //	HOSTUSERNAMEMODULE_CLASS_HPP
