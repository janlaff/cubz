#pragma once

#include <core/Engine.h>

#include "ChunkData.h"
#include "WorldPos.h"
#include "ChunkEntity.h"

namespace cubz::game {
    class World {
    public:
        explicit World(core::Engine* engine);

        void createChunk(int x, int y, int z);
        void destroyChunk(int x, int y, int z);
        ChunkEntity* getChunkEntity(const WorldPos& position);
        BlockType getBlock(int x, int y, int z);
        void setBlock(BlockType blockType, int x, int y, int z);
        WorldPos getChunkPos(int x, int y, int z);

    private:
        core::Engine* m_engine;
        WorldPosMap<std::shared_ptr<ChunkEntity>> m_chunkEntities;
    };

    /*class World {
    public:
        World();

        void setPlayerPosition(const glm::vec3& position);
        void update();
        void render(const graphics::Camera& camera);
        void setBlock(BlockType block, int x, int y, int z);
        void addLight(const WorldPos &position);
        void removeLight(const WorldPos &position);
        void destroyChunk(int x, int y, int z);
        std::shared_ptr<Chunk> createChunk(int x, int y, int z);
        std::shared_ptr<Block> getBlock(int x, int y, int z);
        std::shared_ptr<Chunk> getChunk(int x, int y, int z);
        const WorldPosMap<graphics::opengl::PointLight>& getLights() const;

    private:
        WorldPos getChunkPos(int x, int y, int z);

        WorldPosMap<std::shared_ptr<Chunk>> m_chunks;
        WorldPosMap<graphics::opengl::PointLight> m_lights;
        //Skybox m_skybox;
        glm::vec3 m_playerPosition;
    };*/
}