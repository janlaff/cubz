cmake_minimum_required(VERSION 3.10)

set(
        CUBZ_GAME_SOURCE_FILES
        Block.cpp
        AirBlock.cpp
        GrassBlock.cpp
        DirtBlock.cpp
        TorchBlock.cpp
        World.cpp
        WorldPos.cpp
        main.cpp
        ChunkUpdateSystem.cpp
        ChunkData.cpp
        ChunkEntity.cpp
        ChunkMeshBuilder.cpp
        TorchEntity.cpp
)

add_executable(cubz-game ${CUBZ_GAME_SOURCE_FILES})
target_link_libraries(cubz-game cubz-engine)
target_include_directories(cubz-game PUBLIC .)

file(COPY assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})