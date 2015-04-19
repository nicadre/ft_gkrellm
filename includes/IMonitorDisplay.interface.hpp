#ifndef		IMONITORDISPLAY_INTERFACE_HPP
# define	IMONITORDISPLAY_INTERFACE_HPP

# include "IMonitorModule.interface.hpp"
# include <map>
# include <string>

class IMonitorDisplay {
public:
	typedef std::map<std::string, IMonitorModule *>	t_infos;
	virtual ~IMonitorDisplay(void) {}
	virtual void				display(void) = 0;
};

#endif	//	IMONITORDISPLAY_INTERFACE_HPP
