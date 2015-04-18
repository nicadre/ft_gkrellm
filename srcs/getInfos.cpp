#include "IMonitorModule.interface.hpp"
#include <cstdio>

std::string	getInfos(std::string const & info) {
	FILE	*pipe = popen(info.c_str(), "r");

    if (!pipe)
		return "ERROR";
    char buffer[128];
	std::string result;
    while (!feof(pipe)) {
		if (fgets(buffer, 128, pipe) != NULL)
			result += buffer;
    }
	*(result.end() - 1) = '\0';
    pclose(pipe);
    return result;
}
