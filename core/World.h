#pragma once

#include <unordered_map>
#include <glm/vec3.hpp>

#include "Chunk.h"

namespace core {
    class World {
    public:
        World();

        void createChunk(int x, int y, int z);
        void destroyChunk(int x, int y, int z);
        void update();
        void render(const Camera& camera);

        void setBlock(std::shared_ptr<Block> block, int x, int y, int z);
        std::shared_ptr<Block> getBlock(int x, int y, int z);
        std::shared_ptr<Chunk> getChunk(int x, int y, int z);

    private:
        WorldPos getChunkPos(int x, int y, int z);

        std::unordered_map<WorldPos, std::shared_ptr<Chunk>, WorldPosHash> m_chunks;
    };
}