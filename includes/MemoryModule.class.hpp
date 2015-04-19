#ifndef		MEMORYMODULE_CLASS_HPP
# define	MEMORYMODULE_CLASS_HPP

# include "IMonitorModule.interface.hpp"
# include <iostream>
# include <map>

#define SIZE_TAB_MEMORY 2

class MemoryModule : public IMonitorModule {
private:
	IMonitorModule::t_infos	_infos;

	std::string				_total(void);
	std::string				_used(void);

	MemoryModule(MemoryModule const &);

	MemoryModule const			&operator=(MemoryModule const &);

public:
	MemoryModule(void);

	void				refresh(void);
	void				refresh(std::string const & what);

	virtual ~MemoryModule(void);

	MemoryModule::t_infos const			&infos(void) const;

	typedef struct		s_functions {
		std::string		what;
		std::string		(MemoryModule::*funptr)(void);
	}					t_functions;
};

#endif //	MEMORYMODULE_CLASS_HPP
