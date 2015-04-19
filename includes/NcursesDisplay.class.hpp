#ifndef		NCURSESDISPLAY_CLASS_HPP
# define	NCURSESDISPLAY_CLASS_HPP

# include "IMonitorDisplay.interface.hpp"
# include <curses.h>
# include <unistd.h>

#define QUIT 113
#define RETURN 127
#define HELP 104
#define MAGIC 109
#define NBR_PANELS 2

class NcursesDisplay : public IMonitorDisplay {
private:
	IMonitorDisplay::t_infos	_modules;
	int							_width;
	int							_height;

	static void					_deleteModule(std::pair<std::string, IMonitorModule *> mod);
	std::string const			&_getData(std::string const & module, std::string const & value) const;

	NcursesDisplay(NcursesDisplay const &);

	NcursesDisplay const		&operator=(NcursesDisplay const &);

	void						initNcurses(void) const ;
	void						loopNcurses(void) ;
	void						viewModules(void) const ;
	int							inputUser(void) ;
	int							panelDisplay(void) ;

public:
	NcursesDisplay(void);

	void							display(void) ;

	virtual ~NcursesDisplay(void);

	IMonitorDisplay::t_infos const	&modules(void) const;
	int								width(void) const;
	int								height(void) const;

	void							modules(IMonitorDisplay::t_infos const & modules);
	void							width(int width);
	void							height(int height);

	typedef struct		s_panel {
		int				what;
		void			(NcursesDisplay::*ptr)(void) const;
	}					t_panel;

};

#endif //	NCURSESDISPLAY_CLASS_HPP
