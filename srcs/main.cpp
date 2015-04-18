#include "CPUModule.class.hpp"
#include <iostream>

int		main(int ac, char **av) {
	(void)ac;
	(void)av;

	CPUModule		cpu;

	cpu.refresh();

	IMonitorModule::t_infos		cpuInfos = cpu.infos();

	std::cout << "Welcome to the " << cpuInfos["nbCPU"]
			  << " " << cpuInfos["typeCPU"] << " bulgares!" << std::endl;
}
