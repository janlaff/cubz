#include "Log.h"

namespace cubz::utility {
    std::mutex Log::m_loggerMutex;
    std::list<std::shared_ptr<Logger>> Log::m_loggers;

    void Log::info(const std::string &message) {
        log(LogEntry{LogLevel::info, message});
    }

    void Log::debug(const std::string &message) {
        log(LogEntry{LogLevel::debug, message});
    }

    void Log::warning(const std::string &message) {
        log(LogEntry{LogLevel::warning, message});
    }

    void Log::error(const std::string &message) {
        log(LogEntry{LogLevel::error, message});
    }

    void Log::error(const std::exception &e) {
        log(LogEntry{LogLevel::error, e.what()});
    }

    void Log::addLogger(std::shared_ptr<Logger> logger) {
        std::lock_guard lock(m_loggerMutex);
        m_loggers.push_back(logger);
    }

    void Log::log(const utility::LogEntry &entry) {
        std::lock_guard lock(m_loggerMutex);
        for (const auto &logger : m_loggers) {
            logger->log(entry);
        }
    }
}