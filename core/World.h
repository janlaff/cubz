#pragma once

#include <glm/vec3.hpp>

#include "Chunk.h"
#include "opengl/PointLight.h"

namespace core {
    class World {
    public:
        World();

        std::shared_ptr<Chunk> createChunk(int x, int y, int z);
        void destroyChunk(int x, int y, int z);
        void update();
        void render(const Camera& camera);

        void setBlock(BlockType block, int x, int y, int z);
        std::shared_ptr<Block> getBlock(int x, int y, int z);
        std::shared_ptr<Chunk> getChunk(int x, int y, int z);

        void addLight(const WorldPos &position);
        void removeLight(const WorldPos &position);
        const WorldPosMap<opengl::PointLight>& getLights() const;

    private:
        WorldPos getChunkPos(int x, int y, int z);

        WorldPosMap<std::shared_ptr<Chunk>> m_chunks;
        WorldPosMap<core::opengl::PointLight> m_lights;
    };
}