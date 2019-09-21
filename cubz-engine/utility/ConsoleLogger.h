#pragma once

#include "Logger.h"

#include <mutex>

namespace cubz::utility {
    class ConsoleLogger : public Logger {
    public:
        void log(const LogEntry& entry) override;
    };
}