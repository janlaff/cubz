cmake_minimum_required(VERSION 3.10)

set(
        CORE_SOURCE_FILES
        Engine.cpp
        MeshRenderSystem.cpp
        LightRenderSystem.cpp
        SkyboxRenderSystem.cpp
        TextRenderSystem.cpp
        GameObject.cpp
        Player.cpp
        Text.cpp
        DefaultSystems.cpp
)

add_library(core STATIC ${CORE_SOURCE_FILES})
target_link_libraries(core ecs graphics physics utility)
target_include_directories(core PUBLIC .)