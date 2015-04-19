#ifndef		IMONITORDISPLAY_INTERFACE_HPP
# define	IMONITORDISPLAY_INTERFACE_HPP

class IMonitorDisplay {
public:
	virtual ~IMonitorDisplay(void) {}
	virtual void		display(void) const = 0;
};

std::string	getInfos(std::string const & info);

#endif	//	IMONITORDISPLAY_INTERFACE_HPP
