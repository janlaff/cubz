#include "ChunkData.h"

#include "World.h"

namespace cubz::game {
    ChunkData::ChunkData(World* world, const WorldPos& position)
            : m_world(world)
            , m_position(position)
            , m_update(true) {
        for (auto x = 0; x < CHUNK_SIZE; ++x) {
            for (auto y = 0; y < CHUNK_SIZE; ++y) {
                for (auto z = 0; z < CHUNK_SIZE; ++z) {
                    m_blocks[x][y][z] = BlockType::air;
                }
            }
        }
    }

    WorldPos ChunkData::getPosition() const {
        return m_position;
    }

    BlockType ChunkData::getBlock(int x, int y, int z) const {
        if (inRange(x) && inRange(y) && inRange(z)) {
            return m_blocks[x][y][z];
        } else {
            return m_world->getBlock(m_position.x + x, m_position.y + y, m_position.z + z);
        }
    }

    void ChunkData::setBlock(BlockType block, int x, int y, int z) {
        if (inRange(x) && inRange(y) && inRange(z)) {
            m_blocks[x][y][z] = block;
            m_update = true;
        } else {
            return m_world->setBlock(block, m_position.x + x, m_position.y + y, m_position.z + z);
        }
    }

    bool ChunkData::inRange(int index) const {
        if (index >= 0 && index < CHUNK_SIZE) return true;
    }
}