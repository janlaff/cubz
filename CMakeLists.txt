cmake_minimum_required(VERSION 3.10)

include("cmake/HunterGate.cmake")
HunterGate(
        URL "https://github.com/ruslo/hunter/archive/v0.23.190.tar.gz"
        SHA1 "bc7da329d2493201de28f0c2a5fcd4de1415c477"
)

project(Cubz)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}-build)
set(CMAKE_CXX_STANDARD 17)

hunter_add_package(glfw)
hunter_add_package(glm)
hunter_add_package(glew)
hunter_add_package(stb)
hunter_add_package(freetype)

add_subdirectory(utility)
add_subdirectory(core)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

add_executable(Cubz main.cpp)
target_link_libraries(Cubz utility core)
target_include_directories(Cubz PUBLIC .)