cmake_minimum_required(VERSION 3.10)

set(
        ECS_SOURCE_FILES
        EntityManager.cpp
        SystemManager.cpp
        ComponentManager.cpp
        EntityComponentSystem.cpp
)

add_library(ecs STATIC ${ECS_SOURCE_FILES})
target_link_libraries(ecs utility)
target_include_directories(ecs PUBLIC .)