#include "World.h"
#include "Log.h"
#include "AirBlock.h"

#include <graphics/MeshRenderer.h>

namespace cubz::game {
    World::World(core::Engine *engine) : m_engine(engine) {
        /*const auto numChunks = 2;

        for (int x = -numChunks / 2; x < numChunks; ++x) {
            for (int z = -numChunks / 2; z < numChunks; ++z) {
                createChunk(x * CHUNK_SIZE, -CHUNK_SIZE, z * CHUNK_SIZE);
            }
        }*/
    }

    void World::createChunk(int x, int y, int z) {
        utility::Log::debug("Created chunk");

        auto chunkData = ChunkData(this, WorldPos { x, y, z });

        auto chunk = m_engine->instantiate<ChunkEntity>(chunkData);
        chunk->updateEntity();
        m_chunkEntities.insert({ WorldPos { x, y, z }, chunk });

    }

    void World::destroyChunk(int x, int y, int z) {
        if (auto it = m_chunkEntities.find(WorldPos { x, y, z }); it != m_chunkEntities.end()) {
            m_chunkEntities.erase(it);
        }
    }

    ChunkEntity* World::getChunkEntity(const WorldPos& position) {
        if (auto it = m_chunkEntities.find(position); it != m_chunkEntities.end()) {
            return it->second.get();
        } else {
            return nullptr;
        }
    }

    BlockType World::getBlock(int x, int y, int z) {
        auto chunkPos = getChunkPos(x, y, z);
        auto chunkEntity = getChunkEntity(chunkPos);

        if (chunkEntity) {
            auto& chunkData = chunkEntity->getComponent<ChunkData>();
            return chunkData.getBlock(x - chunkPos.x, y - chunkPos.y, z - chunkPos.z);
        } else {
            return BlockType::air;
        }
    }

    void World::setBlock(cubz::game::BlockType blockType, int x, int y, int z) {
        auto chunkPos = getChunkPos(x, y, z);
        auto chunkEntity = getChunkEntity(chunkPos);

        if (chunkEntity) {
            auto& chunkData = chunkEntity->getComponent<ChunkData>();
            chunkData.setBlock(blockType, x - chunkPos.x, y - chunkPos.y, z - chunkPos.z);
            chunkEntity->updateEntity();
        } else {
            createChunk(chunkPos.x, chunkPos.y, chunkPos.z);
            setBlock(blockType, x, y, z);
        }
    }

    WorldPos World::getChunkPos(int x, int y, int z) {
        auto div = float(CHUNK_SIZE);

        return {
                static_cast<int>(std::floor(x / div) * div),
                static_cast<int>(std::floor(y / div) * div),
                static_cast<int>(std::floor(z / div) * div)
        };
    }

    void World::createTorch(int x, int y, int z) {
        auto pos = WorldPos { x, y, z };
        auto torchEntity = m_engine->instantiate<Torch>(pos);
        torchEntity->updateEntity();
        m_torchEntities.insert({ pos, torchEntity });
    }

    void World::destroyTorch(int x, int y, int z) {
        if (auto it = m_torchEntities.find(WorldPos { x, y, z }); it != m_torchEntities.end()) {
            m_torchEntities.erase(it);
        }
    }
}