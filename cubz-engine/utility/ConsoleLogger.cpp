#include "ConsoleLogger.h"

#include <map>
#include <iostream>

namespace cubz::utility {
    void ConsoleLogger::log(const LogEntry &entry) {
        std::cout << timeToString(std::chrono::system_clock::now()) << " ";
        std::cout << logLevelToString(entry.level) << ": ";
        std::cout << entry.message << std::endl;
    }
}