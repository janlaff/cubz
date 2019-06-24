#include "World.h"
#include "AirBlock.h"
#include "GrassBlock.h"
#include "Log.h"

namespace core {
    World::World() {
        createChunk(0, 0, 0);
        createChunk(16, 0, 0);
        createChunk(-16, 0, 0);
        createChunk(0, 0, 16);
        createChunk(0, 0, -16);
    }

    void World::createChunk(int x, int y, int z) {
        auto pos = WorldPos{x, y, z};
        auto chunk = std::make_shared<Chunk>(this, pos);

        for (int x = 0; x < chunkSize; ++x) {
            for (int z = 0; z < chunkSize; ++z) {
                chunk->setBlock(std::make_shared<GrassBlock>(), x, 0, z);
            }
        }

        m_chunks.insert({pos, chunk});
    }

    void World::destroyChunk(int x, int y, int z) {
        if (auto chunk = m_chunks.find(WorldPos { x, y, z }); chunk != m_chunks.end()) {
            m_chunks.erase(chunk);
        }
    }

    void World::update() {
        for (auto&[pos, chunk] : m_chunks) {
            chunk->update();
        }
    }

    void World::render(const Camera &camera) {
        for (auto&[pos, chunk] : m_chunks) {
            chunk->render(camera);
        }
    }

    void World::setBlock(std::shared_ptr<core::Block> block, int x, int y, int z) {
        auto chunk = getChunk(x, y, z);

        if (chunk) {
            auto pos = chunk->getPosition();
            chunk->setBlock(std::move(block), x - pos.x, y - pos.y, z - pos.z);
        } else {
            utility::Log::warning("Failed to set block");
        }
    }

    std::shared_ptr<Block> World::getBlock(int x, int y, int z) {
        auto chunk = getChunk(x, y, z);

        if (chunk) {
            auto pos = chunk->getPosition();
            return chunk->getBlock(x - pos.x, y - pos.y, z - pos.z);
        } else {
            return std::make_shared<AirBlock>();
        }
    }

    std::shared_ptr<Chunk> World::getChunk(int x, int y, int z) {
        if (auto chunk = m_chunks.find(getChunkPos(x, y, z)); chunk != m_chunks.end()) {
            return chunk->second;
        } else {
            return {};
        }
    }

    WorldPos World::getChunkPos(int x, int y, int z) {
        auto div = float(chunkSize);

        return {
            static_cast<int>(std::floor(x / div) * chunkSize),
            static_cast<int>(std::floor(y / div) * chunkSize),
            static_cast<int>(std::floor(z / div) * chunkSize)
        };
    }
}