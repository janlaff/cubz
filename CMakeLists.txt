cmake_minimum_required(VERSION 3.10)

include("cmake/HunterGate.cmake")
HunterGate(
        URL "https://github.com/ruslo/hunter/archive/v0.23.190.tar.gz"
        SHA1 "bc7da329d2493201de28f0c2a5fcd4de1415c477"
)

project(Cubz)

set(CMAKE_CXX_STANDARD 17)

hunter_add_package(glfw)
hunter_add_package(glm)
hunter_add_package(glew)

add_subdirectory(utility)
add_subdirectory(graphics)
add_subdirectory(main)