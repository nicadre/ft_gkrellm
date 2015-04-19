#define QUIT 113
#define RETURN 127
#define HELP 104
#define MAGIC 109
#define WIDTH 300
#define HEIGHT 100
#define NBR_PANELS 2


#include "CPUModule.class.hpp"
#include "HostUsernameModule.class.hpp"
#include "OSModule.class.hpp"
#include "TimeModule.class.hpp"
#include "MemoryModule.class.hpp"
#include <iostream>
#include <curses.h>
#include <unistd.h>
#include <cstdlib>
#include <math.h>

#include <form.h>

int		cHeight = 0;
int		cWidth = 0;
int		bHeight = 0;
int		bWidth = 0;

void	seeHelp();
void	seeMagic();
int		inputUser();

void	displayShortcuts() {
//	attron(COLOR_PAIR(4));
	mvprintw(cHeight - 2, 2, " h Help");
//	attroff(COLOR_PAIR(4));
}

int		panelDisplay() {
	getmaxyx(stdscr, cHeight, cWidth);
	if (bWidth != cWidth || bHeight != cHeight) {
		clear();
		bWidth = cWidth;
		bHeight = cHeight;
	}
	attron(COLOR_PAIR(4));
	for (int i = 0 ; i < cHeight - 1 ; i++) {
		if (i == 0 || i == cHeight - 2)
			for (int j = 0 ; j < cWidth ; j++)
				mvprintw(i, j, " ");
		else {
			mvprintw(i, 0, " ");
			mvprintw(i, cWidth - 1, " ");
		}
	}
	mvprintw(0, (cWidth / 2 - 9), "Informations system");
	displayShortcuts();
	attroff(COLOR_PAIR(4));
	return(0);
}

typedef struct		s_panel {
	int		what;
	int		(*ptr)(void);
}					t_panel;

int		checkPanel(int input) {
	t_panel		panels[NBR_PANELS] = {
		{ 'm' , &seeMagic },
		{ 'h' , &seeHelp }
	};

	for (int i = 0 ; i < NBR_PANELS ; i++) {
		if (panels[i].what == input || panels[i].what == input - 32) {
			clear();
			panelDisplay();

			(*(panels[i].ptr))();

			refresh();
			while ((input = getch()) != RETURN) {
				if (inputUser())
					return (1);
			}
			clear();
			panelDisplay();
			break ;
		}
	}
	return (0);
}

int		inputUser() {
	int	input = 0;
	input = getch();
	if (input == QUIT || input == QUIT - 32)
		return (1);
	if (input == HELP || input == HELP - 32)
		if (checkPanel(HELP))
			return (1);
	if (input == MAGIC || input == MAGIC - 32)
		if (checkPanel(MAGIC))
			return (1);
	return (0);
}

void	seeMagic() {
	mvprintw(1, 2, " Magic bitch");
}

void	seeHelp() {
	mvprintw(1, 2, " Q for quit moube          M for seeing magic");
}

void	loop_ncurse(IMonitorModule::t_infos cpu, IMonitorModule::t_infos host,
 IMonitorModule::t_infos os, IMonitorModule::t_infos time, IMonitorModule::t_infos memory) {
	/* Maybe with window... */

	std::string	tmp;

/*	(void)cpu;
	(void)host;
	(void)os;
	(void)time;
	(void)memory;*/
	while (42) {
		panelDisplay();
		if (inputUser())
			return ;
		attron(COLOR_PAIR(4));
		mvprintw(2, 1, "  CPU informations  ");
		attroff(COLOR_PAIR(4));
		tmp = cpu["nbCPU"];
		mvprintw(3, 2, "Number of CPUs: %s", tmp.c_str());
		tmp = cpu["typeCPU"];
		mvprintw(4, 2, "Type of CPU: %s", tmp.c_str());
		attron(COLOR_PAIR(4));
		mvprintw(6, 1, "  Host informations  ");
		attroff(COLOR_PAIR(4));
		tmp = host["hostName"];
		mvprintw(7, 2, "Host name: %s", tmp.c_str());
		attron(COLOR_PAIR(4));
		mvprintw(9, 1, "  OS informations  ");
		attroff(COLOR_PAIR(4));
		tmp = os["osType"];
		mvprintw(10, 2, "OS: %s", tmp.c_str());
		tmp = os["productName"];
		mvprintw(11, 2, "Product name: %s", tmp.c_str());
		tmp = os["productVersion"];
		mvprintw(12, 2, "Product version: %s", tmp.c_str());
		attron(COLOR_PAIR(4));
		mvprintw(14, 1, "  Time informations  ");
		attroff(COLOR_PAIR(4));
		tmp = time["date"];
		mvprintw(15, 2, "Date: %s", tmp.c_str());
		attron(COLOR_PAIR(4));
		mvprintw(17, 1, "  Memory informations  ");
		attroff(COLOR_PAIR(4));
		tmp = memory["total"];
		mvprintw(18, 2, "Total memory: %s", tmp.c_str());

		refresh();
		usleep(50000);
	}
}

void	voidinit() {
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

void	display_ncurse(IMonitorModule::t_infos cpu, IMonitorModule::t_infos host, IMonitorModule::t_infos os,
 IMonitorModule::t_infos time, IMonitorModule::t_infos memory) {
	voidinit();
	loop_ncurse(cpu, host, os, time, memory);
	endwin();
}
