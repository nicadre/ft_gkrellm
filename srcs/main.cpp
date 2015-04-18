#include "CPUModule.class.hpp"
#include "HostUsernameModule.class.hpp"
#include "OSModule.class.hpp"
#include <iostream>

int		main(int ac, char **av) {
	(void)ac;
	(void)av;

	CPUModule			cpu;
	HostUsernameModule	host;
	OSModule			os;

	cpu.refresh();
	host.refresh();
	os.refresh();

	IMonitorModule::t_infos		cpuInfos = cpu.infos();
	IMonitorModule::t_infos		hostInfos = host.infos();
	IMonitorModule::t_infos		osInfos = os.infos();

	std::cout << "Welcome\n" << std::endl;
	std::cout << "~~~~ CPU informations ~~~~\n"
			  << "Number of CPUs: " << cpuInfos["nbCPU"] << "\n"
			  << "Type of CPU: " << cpuInfos["typeCPU"] << "\n" << std::endl;
	std::cout << "~~~~ host / user informations ~~~~\n"
			  << "Hostname: " << hostInfos["hostName"] << "\n" << std::endl;
	std::cout << "~~~~ OS informations ~~~~\n"
			  << "OS: " << osInfos["osType"] << "\n"
			  << "OS: " << osInfos["productName"] << "\n"
			  << "OS: " << osInfos["productVersion"] << "\n" << std::endl;
}
