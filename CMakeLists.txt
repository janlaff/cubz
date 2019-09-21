cmake_minimum_required(VERSION 3.10)

include("./cmake/HunterGate.cmake")
HunterGate(
        URL "https://github.com/ruslo/hunter/archive/v0.23.190.tar.gz"
        SHA1 "bc7da329d2493201de28f0c2a5fcd4de1415c477"
)

project(cubz)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}-build)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(cubz-engine)
add_subdirectory(cubz-game)
add_subdirectory(cubz-test)