#pragma once

#include <string>
#include <chrono>

namespace utility {
    enum class LogLevel {
        info, debug, warning, error
    };

    struct LogEntry {
        LogLevel level;
        std::string message;
    };

    std::string logLevelToString(LogLevel level);
    std::string timeToString(const std::chrono::system_clock::time_point& timePoint);

    class Logger {
    public:
        virtual void log(const LogEntry& entry) = 0;
    };
}