#pragma once

#include "Logger.h"

#include <mutex>

namespace utility {
    class ConsoleLogger : public Logger {
    public:
        void log(const LogEntry& entry) override;

    private:
        std::mutex m_outputMutex;
    };
}