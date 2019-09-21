cmake_minimum_required(VERSION 3.10)

hunter_add_package(glfw)
hunter_add_package(glm)
hunter_add_package(glew)
hunter_add_package(stb)
hunter_add_package(freetype)
hunter_add_package(bullet)
hunter_add_package(imgui)

add_subdirectory(core)
add_subdirectory(ecs)
add_subdirectory(graphics)
add_subdirectory(physics)
add_subdirectory(utility)

add_library(cubz-engine INTERFACE)
target_link_libraries(cubz-engine INTERFACE core ecs graphics physics utility)
target_include_directories(cubz-engine INTERFACE .)

file(COPY assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})