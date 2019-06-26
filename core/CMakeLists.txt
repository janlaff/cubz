cmake_minimum_required(VERSION 3.10)

add_subdirectory(opengl)
add_subdirectory(ui)
add_subdirectory(physics)

set(
        CORE_SOURCE_FILES
        MeshData.cpp
        Screen.cpp
        Camera.cpp
        MeshRenderer.cpp
        ResourceManager.cpp
        Block.cpp
        AirBlock.cpp
        GrassBlock.cpp
        DirtBlock.cpp
        TorchBlock.cpp
        Chunk.cpp
        World.cpp
        WorldPos.cpp
        TorchRenderer.cpp
        Skybox.cpp
)

add_library(core STATIC ${CORE_SOURCE_FILES})
target_link_libraries(core opengl ui)
target_include_directories(core PUBLIC .)