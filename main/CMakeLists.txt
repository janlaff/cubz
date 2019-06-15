cmake_minimum_required(VERSION 3.10)

find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(glew CONFIG REQUIRED)

add_executable(Cubz main.cpp)
target_link_libraries(Cubz glfw glm glew::glew utility)