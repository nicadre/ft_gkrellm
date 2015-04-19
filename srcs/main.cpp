#include "NcursesDisplay.class.hpp"
#include "CPUModule.class.hpp"
#include "HostUsernameModule.class.hpp"
#include "OSModule.class.hpp"
#include "TimeModule.class.hpp"
#include "MemoryModule.class.hpp"
#include <iostream>

int		main(int ac, char **av) {
	(void)ac;
	(void)av;

//	CPUModule			cpu;
	HostUsernameModule	host;
	OSModule			os;
	TimeModule			time;
	MemoryModule		memory;

	//cpu.refresh();
	host.refresh();
	os.refresh();
	time.refresh();
	memory.refresh();

//	IMonitorModule::t_infos		cpuInfos = cpu.infos();
	IMonitorModule::t_infos		hostInfos = host.infos();
	IMonitorModule::t_infos		osInfos = os.infos();
	IMonitorModule::t_infos		timeInfos = time.infos();
	IMonitorModule::t_infos		memoryInfos = memory.infos();

	NcursesDisplay toto;

	toto.display();

// 	std::cout << "Welcome\n" << std::endl;
// 	std::cout << "~~~~ CPU informations ~~~~\n"
// 			  << "Number of CPUs: " << cpuInfos["nbCPU"] << "\n"
// 			  << "Type of CPU: " << cpuInfos["typeCPU"] << "\n" << std::endl;
// 	std::cout << "~~~~ Host informations ~~~~\n"
// 			  << "Hostname: " << hostInfos["hostName"] << "\n" << std::endl;
// 	std::cout << "~~~~ OS informations ~~~~\n"
// 			  << "OS: " << osInfos["osType"] << "\n"
// 			  << "OS: " << osInfos["productName"] << "\n"
// 			  << "OS: " << osInfos["productVersion"] << "\n" << std::endl;
// 	std::cout << "~~~~ Time informations ~~~~\n"
// 			  << "Date: " << timeInfos["date"] << "\n" << std::endl;
// 	std::cout << "~~~~ Memory informations ~~~~\n"
// 			  << "Total: " << memoryInfos["total"] << "\n" << std::endl;

}
