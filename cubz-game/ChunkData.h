#pragma once

#include <array>

#include "BlockType.h"
#include "WorldPos.h"

namespace cubz::game {
    const auto CHUNK_SIZE = 16;

    class World;

    class ChunkData {
    public:
        ChunkData() = default;
        ChunkData(World* world, const WorldPos& position);

        WorldPos getPosition() const;
        BlockType getBlock(int x, int y, int z) const;
        void setBlock(BlockType block, int x, int y, int z);

    private:
        bool inRange(int index) const;

        std::array<std::array<std::array<BlockType, CHUNK_SIZE>, CHUNK_SIZE>, CHUNK_SIZE> m_blocks;
        WorldPos m_position;
        World* m_world;
    };
}