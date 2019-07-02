cmake_minimum_required(VERSION 3.10)

set(
        UTILITY_SOURCE_FILES
        Logger.cpp
        ConsoleLogger.cpp
        Log.cpp
        Helpers.cpp
)

add_library(utility STATIC ${UTILITY_SOURCE_FILES})
target_link_libraries(utility graphics)
target_include_directories(utility PUBLIC .)