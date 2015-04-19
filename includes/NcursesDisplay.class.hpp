#ifndef		NCURSESDISPLAY_CLASS_HPP
# define	NCURSESDISPLAY_CLASS_HPP

# include "IMonitorDisplay.class.hpp"

class NcursesDisplay : public IMonitorDisplay {
private:
	std::map<std::string, IMonitorModule>			_modules;
	int			_width;
	int			_height;
public:
	NcursesDisplay(void);
	NcursesDisplay(NcursesDisplay const & src);

	virtual ~NcursesDisplay(void);

	NcursesDisplay const			&operator=(NcursesDisplay const & rhs);

	void			modules(std::map<std::string, IMonitorModule> modules);
	void			width(int width);
	void			height(int height);
};

#endif //	NCURSESDISPLAY_CLASS_HPP
