#include "Logger.h"

#include <sstream>
#include <array>

namespace cubz::utility {
    std::string logLevelToString(LogLevel level) {
        switch (level) {
            case LogLevel::info:
                return "info";
            case LogLevel::debug:
                return "debug";
            case LogLevel::warning:
                return "warning";
            case LogLevel::error:
                return "error";
        }
    }

    std::string timeToString(const std::chrono::system_clock::time_point& timePoint) {
        std::array<char, 20> buf { 0 };
        auto time_t = std::chrono::system_clock::to_time_t(timePoint);
        strftime(buf.data(), 20, "%Y-%m-%d %H:%M:%S", localtime(&time_t));

        return { buf.begin() };
    }
}