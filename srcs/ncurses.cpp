#define QUIT 113
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

void	loop_ncurse(IMonitorModule::t_infos cpu, IMonitorModule::t_infos host,
 IMonitorModule::t_infos os, IMonitorModule::t_infos time, IMonitorModule::t_infos memory) {
	/* Maybe with window... */

	int	input = 0;
	std::string	tmp;

	(void)memory;
	while (42) {
		input = getch();
		if (input == QUIT)
			return ;
		attron(COLOR_PAIR(4));
		mvprintw(0, 0, "  CPU informations  ");
		attroff(COLOR_PAIR(4));
		tmp = cpu["nbCPU"];
		mvprintw(1, 0, "Number of CPUs: %s", tmp.c_str());
		tmp = cpu["typeCPU"];
		mvprintw(2, 0, "Type of CPU: %s", tmp.c_str());
		attron(COLOR_PAIR(4));
		mvprintw(4, 0, "  Host informations  ");
		attroff(COLOR_PAIR(4));
		tmp = host["hostName"];
		mvprintw(5, 0, "Host name: %s", tmp.c_str());
		attron(COLOR_PAIR(4));
		mvprintw(7, 0, "  OS informations  ");
		attroff(COLOR_PAIR(4));
		tmp = os["osType"];
		mvprintw(8, 0, "OS: %s", tmp.c_str());
		tmp = os["productName"];
		mvprintw(9, 0, "Product name: %s", tmp.c_str());
		tmp = os["productVersion"];
		mvprintw(10, 0, "Product version: %s", tmp.c_str());
		attron(COLOR_PAIR(4));
		mvprintw(12, 0, "  Time informations  ");
		attroff(COLOR_PAIR(4));
		tmp = time["date"];
		mvprintw(13, 0, "Date: %s", tmp.c_str());
		attron(COLOR_PAIR(4));
		mvprintw(15, 0, "  Memory informations  ");
		attroff(COLOR_PAIR(4));
		tmp = memory["total"];
		mvprintw(16, 0, "Total memory: %s", tmp.c_str());

		attron(COLOR_PAIR(2));
		mvprintw(18, 0, " Q for quit moube");
		attroff(COLOR_PAIR(2));
		refresh();
		usleep(5000);
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
