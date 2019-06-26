#pragma once

#include <glm/vec3.hpp>

#include "Chunk.h"
#include "Skybox.h"
#include "opengl/PointLight.h"

namespace core {
    class World {
    public:
        World();

        void setPlayerPosition(const glm::vec3& position);
        void update();
        void render(const Camera& camera);
        void setBlock(BlockType block, int x, int y, int z);
        void addLight(const WorldPos &position);
        void removeLight(const WorldPos &position);
        void destroyChunk(int x, int y, int z);
        std::shared_ptr<Chunk> createChunk(int x, int y, int z);
        std::shared_ptr<Block> getBlock(int x, int y, int z);
        std::shared_ptr<Chunk> getChunk(int x, int y, int z);
        const WorldPosMap<opengl::PointLight>& getLights() const;

    private:
        WorldPos getChunkPos(int x, int y, int z);

        WorldPosMap<std::shared_ptr<Chunk>> m_chunks;
        WorldPosMap<core::opengl::PointLight> m_lights;
        Skybox m_skybox;
        glm::vec3 m_playerPosition;
    };
}