cmake_minimum_required(VERSION 3.10)

add_subdirectory(opengl)
add_subdirectory(ui)

set(
        CORE_SOURCE_FILES
        Model.cpp
        Mesh.cpp
        Screen.cpp
        Camera.cpp
        MeshRenderer.cpp
        ShaderManager.cpp
)

add_library(core STATIC ${CORE_SOURCE_FILES})
target_link_libraries(core opengl ui)
target_include_directories(core PUBLIC .)