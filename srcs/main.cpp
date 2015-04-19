#include "CPUModule.class.hpp"
#include "HostUsernameModule.class.hpp"
#include "OSModule.class.hpp"
#include "TimeModule.class.hpp"
#include "MemoryModule.class.hpp"
#include <iostream>

void	display_ncurse(IMonitorModule::t_infos cpu, IMonitorModule::t_infos host, IMonitorModule::t_infos os,
					   IMonitorModule::t_infos time, IMonitorModule::t_infos memory);


int		main(int ac, char **av) {
	(void)ac;
	(void)av;

	CPUModule			cpu;
	HostUsernameModule	host;
	OSModule			os;
	TimeModule			time;
	MemoryModule		memory;

	cpu.refresh();
	host.refresh();
	os.refresh();
	time.refresh();
	memory.refresh();

	IMonitorModule::t_infos		cpuInfos = cpu.infos();
	IMonitorModule::t_infos		hostInfos = host.infos();
	IMonitorModule::t_infos		osInfos = os.infos();
	IMonitorModule::t_infos		timeInfos = time.infos();
	IMonitorModule::t_infos		memoryInfos = memory.infos();

	std::cout << "Welcome\n" << std::endl;
	std::cout << "~~~~ CPU informations ~~~~\n"
			  << "Number of CPUs: " << cpuInfos["nbCPU"] << "\n"
			  << "Type of CPU: " << cpuInfos["typeCPU"] << "\n" << std::endl;
	std::cout << "~~~~ Host informations ~~~~\n"
			  << "Hostname: " << hostInfos["hostName"] << "\n" << std::endl;
	std::cout << "~~~~ OS informations ~~~~\n"
			  << "OS: " << osInfos["osType"] << "\n"
			  << "OS: " << osInfos["productName"] << "\n"
			  << "OS: " << osInfos["productVersion"] << "\n" << std::endl;
	std::cout << "~~~~ Time informations ~~~~\n"
			  << "Date: " << timeInfos["date"] << "\n" << std::endl;
	std::cout << "~~~~ Memory informations ~~~~\n"
			  << "Total: " << memoryInfos["total"] << "\n" << std::endl;

	display_ncurse(cpuInfos, hostInfos, osInfos, timeInfos, memoryInfos);
}
