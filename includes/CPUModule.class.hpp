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
	void					_toto(std::pair<std::string, std::string> & pair);

public:
	CPUModule(void);

	/*
	** pour chaque info, il faut faire une fonction en private
	** qui va return la sortie de getInfos();
	** refresh(void): for_each(_infos.begin(), _infos.end(), _toto)
	** _toto(pair) { this->refresh(pair.first()); }
	**
	** refresh(string): funptr;
	**      this->_infos[string] = (this->*(funptr[i].func))();
	*/

	void			refresh(void);
	void			refresh(std::string const & what);

	virtual ~CPUModule(void);

	std::map<std::string, std::string> const	&infos(void) const;
};

#endif //	CPUMODULE_CLASS_HPP
