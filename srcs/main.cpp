#include "CPUModule.class.hpp"
#include "HostUsernameModule.class.hpp"
#include <iostream>

int		main(int ac, char **av) {
	(void)ac;
	(void)av;

	CPUModule			cpu;
	HostUsernameModule	host;

	cpu.refresh();
	host.refresh();

	IMonitorModule::t_infos		cpuInfos = cpu.infos();
	IMonitorModule::t_infos		hostInfos = host.infos();

	std::cout << "Welcome\n" << std::endl;
	std::cout << "~~~~ CPU informations ~~~~\n"
			  << "Number of CPUs: " << cpuInfos["nbCPU"] << "\n"
			  << "Type of CPU: " << cpuInfos["typeCPU"] << "\n" << std::endl;
	std::cout << "~~~~ host / user informations ~~~~\n"
			  << "Hostname: " << hostInfos["hostName"] << "\n" << std::endl;
}
