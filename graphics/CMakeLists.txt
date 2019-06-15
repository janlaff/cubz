cmake_minimum_required(VERSION 3.10)

find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(glew CONFIG REQUIRED)

set(
        GRAPHICS_SOURCE_FILES
        OpenGLContext.cpp
        OpenGLShader.cpp
        OpenGLVertexArray.cpp
)

add_subdirectory(shaders)

add_library(graphics STATIC ${GRAPHICS_SOURCE_FILES})
target_link_libraries(graphics glfw glm glew::glew utility)
target_include_directories(graphics PUBLIC .)