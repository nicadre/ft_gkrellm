#ifndef		IMONITORMODULE_INTERFACE_HPP
# define	IMONITORMODULE_INTERFACE_HPP

# include <string>
# include <map>

class IMonitorModule {
public:
	virtual ~IMonitorModule(void) {}
	virtual std::map<std::string, std::string>const	&infos(void) const = 0;
	virtual void									refresh(void) = 0;
	virtual void									refresh(std::string const & what) = 0;
};

std::string	getInfos(std::string const & info);

#endif	//	IMONITORMODULE_INTERFACE_HPP
