cmake_minimum_required(VERSION 3.10)

add_subdirectory(opengl)

set(
        GRAPHICS_SOURCES
        Model.cpp
)

add_library(graphics STATIC ${GRAPHICS_SOURCE_FILES})
target_link_libraries(graphics opengl)
target_include_directories(graphics PUBLIC .)