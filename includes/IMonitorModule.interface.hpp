#ifndef		IMONITORMODULE_INTERFACE_HPP
# define	IMONITORMODULE_INTERFACE_HPP

# include <string>
# include <map>

class IMonitorModule {
public:
	typedef std::map<std::string, std::string> t_infos;
	virtual ~IMonitorModule(void) {}
	virtual t_infos const		&infos(void) const = 0;
	virtual void			refresh(void) = 0;
	virtual void			refresh(std::string const & what) = 0;
};

std::string	getInfos(std::string const & info);

#endif	//	IMONITORMODULE_INTERFACE_HPP
