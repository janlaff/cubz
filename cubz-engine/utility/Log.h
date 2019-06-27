#pragma once

#include "Logger.h"

#include <list>
#include <mutex>
#include <memory>

namespace cubz::utility {
    class Log {
    public:
        static void info(const std::string& message);
        static void debug(const std::string& message);
        static void warning(const std::string& message);
        static void error(const std::string& message);
        static void error(const std::exception& e);

        static void addLogger(std::shared_ptr<Logger> logger);

    private:
        static void log(const LogEntry& entry);

        static std::mutex m_loggerMutex;
        static std::list<std::shared_ptr<Logger>> m_loggers;
    };
}