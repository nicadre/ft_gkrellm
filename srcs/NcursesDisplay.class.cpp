#include "NcursesDisplay.class.hpp"
#include "CPUModule.class.hpp"
#include "OSModule.class.hpp"
#include "MemoryModule.class.hpp"
#include "HostUsernameModule.class.hpp"
#include "TimeModule.class.hpp"

NcursesDisplay::NcursesDisplay(void) {
	this->_modules[" cpu"] = new CPUModule;
	this->_modules["  os"] = new OSModule;
	this->_modules[" ram"] = new MemoryModule;
	this->_modules["host"] = new HostUsernameModule;
	this->_modules["time"] = new TimeModule;
}

NcursesDisplay::NcursesDisplay(NcursesDisplay const &) {}

void							NcursesDisplay::_deleteModule(std::pair<std::string, IMonitorModule *> mod) {
	delete mod.second;
}

std::string const				&NcursesDisplay::_getData(std::string const & module, std::string const & value) const {
	return (this->_modules.find(module)->second->infos()).find(value)->second;
}

void							NcursesDisplay::initNcurses() const {
	initscr();
	raw();
	noecho();
	curs_set(0);
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_BLACK, COLOR_WHITE);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_WHITE, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
	return ;
}

int								NcursesDisplay::panelDisplay() {
	int		tmpHeight = 0;
	int		tmpWidth = 0;

	getmaxyx(stdscr, tmpHeight, tmpWidth);
	if (tmpWidth != this->_width || tmpHeight != this->_height) {
		clear();
		this->width(tmpWidth);
		this->height(tmpHeight);
	}
	attron(COLOR_PAIR(4));
	for (int i = 0 ; i < this->_height - 1 ; i++) {
		if (i == 0 || i == this->_height - 2)
			for (int j = 0 ; j < this->_width ; j++)
				mvprintw(i, j, " ");
		else {
			mvprintw(i, 0, " ");
			mvprintw(i, this->_width - 1, " ");
		}
	}
	mvprintw(0, (this->_width / 2 - 9), "Informations system");
	mvprintw(this->_height - 2, 2, " Quit(q/Q)");
	attroff(COLOR_PAIR(4));
	return(0);
}

int								NcursesDisplay::inputUser() {
	int			input = 0;

	input = getch();
	if (input == QUIT || input == QUIT - 32)
		return (1);
	return (0);
}

void							NcursesDisplay::viewModules(void) const {
	int					x = 2;

	for (IMonitorDisplay::t_infos::const_iterator curs = this->_modules.begin();
		curs != this->_modules.end(); curs++) {
		attron(COLOR_PAIR(4));
		mvprintw(x, 1, "          %s informations          ", curs->first.c_str());
		attroff(COLOR_PAIR(4));
		x++;
		curs->second->refresh();
		IMonitorModule::t_infos const & infosModule = curs->second->infos();

		for (IMonitorModule::t_infos::const_iterator curs2 = infosModule.begin();
			 curs2 != infosModule.end(); curs2++) {
			mvprintw(x, 1, " %s: %s", curs2->first.c_str(), curs2->second.c_str());
			x++;
		}
		x++;
	}
}

void							NcursesDisplay::loopNcurses(void) {
	while (42) {
		this->panelDisplay();
		if (this->inputUser())
			return ;
		this->viewModules();
		refresh();
		usleep(300000);
	}
}

void							NcursesDisplay::display(void) {
	this->initNcurses();
	this->loopNcurses();
	endwin();
}

NcursesDisplay::~NcursesDisplay(void) {
	for_each(this->_modules.begin(), this->_modules.end(), this->_deleteModule);
}

NcursesDisplay const			&NcursesDisplay::operator=(NcursesDisplay const &) { return (*this); }

IMonitorDisplay::t_infos const	&NcursesDisplay::modules(void) const { return (this->_modules); }
int								NcursesDisplay::width(void) const { return (this->_width); }
int								NcursesDisplay::height(void) const { return (this->_height); }

void							NcursesDisplay::modules(IMonitorDisplay::t_infos const & modules) { this->_modules = modules; }
void							NcursesDisplay::width(int width) { this->_width = width; }
void							NcursesDisplay::height(int height) { this->_height = height; }
