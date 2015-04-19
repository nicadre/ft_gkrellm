#ifndef		NCURSESDISPLAY_CLASS_HPP
# define	NCURSESDISPLAY_CLASS_HPP

# include "IMonitorDisplay.interface.hpp"

class NcursesDisplay : public IMonitorDisplay {
private:
	IMonitorDisplay::t_infos	_modules;
	int							_width;
	int							_height;

	static void					_deleteModule(std::pair<std::string, IMonitorModule *> mod);
	std::string const			&_giveMePlease(std::string const & module, std::string const & value) const;

	NcursesDisplay(NcursesDisplay const &);

	NcursesDisplay const		&operator=(NcursesDisplay const &);

public:
	NcursesDisplay(void);

	void							display(void) const;

	virtual ~NcursesDisplay(void);

	IMonitorDisplay::t_infos const	&modules(void) const;
	int								width(void) const;
	int								height(void) const;

	void							modules(IMonitorDisplay::t_infos const & modules);
	void							width(int width);
	void							height(int height);
};

#endif //	NCURSESDISPLAY_CLASS_HPP
