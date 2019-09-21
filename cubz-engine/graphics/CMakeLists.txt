cmake_minimum_required(VERSION 3.10)

add_subdirectory(opengl)
add_subdirectory(ui)
add_subdirectory(gui)

set(
        GRAPHICS_SOURCE_FILES
        Mesh.cpp
        Camera.cpp
        MeshRenderer.cpp
        SkyboxRenderer.cpp
        ResourceManager.cpp
        PointLight.cpp
        DirectionalLight.cpp
)

add_library(graphics STATIC ${GRAPHICS_SOURCE_FILES})
target_link_libraries(graphics opengl ui gui)
target_include_directories(graphics PUBLIC .)