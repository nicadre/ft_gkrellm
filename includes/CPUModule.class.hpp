#ifndef		CPUMODULE_CLASS_HPP
# define	CPUMODULE_CLASS_HPP

# include "IMonitorModule.interface.hpp"
# include <iostream>
# include <map>

#define SIZE_TAB_CPU 2

class CPUModule : public IMonitorModule {
private:
	IMonitorModule::t_infos	_infos;

	std::string				_nbCPU(void);
	std::string				_typeCPU(void);

	CPUModule(CPUModule const &);

	CPUModule const			&operator=(CPUModule const &);

public:
	CPUModule(void);

	void				refresh(void);
	void				refresh(std::string const & what);

	virtual ~CPUModule(void);

	CPUModule::t_infos const			&infos(void) const;

	typedef struct		s_functions {
		std::string		what;
		std::string		(CPUModule::*funptr)(void);
	}					t_functions;
};

#endif //	CPUMODULE_CLASS_HPP
