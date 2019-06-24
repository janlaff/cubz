cmake_minimum_required(VERSION 3.10)

add_subdirectory(opengl)
add_subdirectory(ui)

set(
        GRAPHICS_SOURCE_FILES
        Model.cpp
        Mesh.cpp
        Screen.cpp
        Camera.cpp
        MeshRenderer.cpp
        ShaderManager.cpp
)

add_library(graphics STATIC ${GRAPHICS_SOURCE_FILES})
target_link_libraries(graphics opengl ui)
target_include_directories(graphics PUBLIC .)