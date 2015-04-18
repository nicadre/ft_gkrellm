#ifndef		CPUMODULE_CLASS_HPP
# define	CPUMODULE_CLASS_HPP

# include "IMonitorModule.interface.hpp"
# include <iostream>
# include <map>

class CPUModule : public IMonitorModule {
private:
	std::map<std::string, std::string>			_infos;

	CPUModule(CPUModule const &);

	CPUModule const			&operator=(CPUModule const &);

public:
	CPUModule(void);

	virtual ~CPUModule(void);

	std::map<std::string, std::string> const	&infos(void) const;
};

#endif //	CPUMODULE_CLASS_HPP
