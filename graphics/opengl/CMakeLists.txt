cmake_minimum_required(VERSION 3.10)

find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(glew CONFIG REQUIRED)
find_package(stb CONFIG REQUIRED)

set(
        OPENGL_SOURCE_FILES
        Context.cpp
        Shader.cpp
        VertexArray.cpp
        VertexBuffer.cpp
        ElementBuffer.cpp
        Texture.cpp
        UvBuffer.cpp
)

add_library(opengl STATIC ${OPENGL_SOURCE_FILES})
target_link_libraries(opengl glfw glm glew::glew utility stb::stb)