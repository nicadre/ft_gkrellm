#include "CPUModule.class.hpp"
#include <iostream>

int		main(int ac, char **av) {
	(void)ac;
	(void)av;

	CPUModule		cpu;

	cpu.refresh();

	IMonitorModule::t_infos		cpuInfos = cpu.infos();

	std::cout << "Welcome\n" << std::endl;
	std::cout << "~~~~ CPU informations ~~~~\n"
			  << "Number of CPUs: " << cpuInfos["nbCPU"] << "\n"
			  << "Type of CPU: " << cpuInfos["typeCPU"] << "\n" << std::endl;
}
