#include <utility>

#include "ChunkMeshBuilder.h"
#include "Block.h"
#include "AirBlock.h"
#include "DirtBlock.h"
#include "GrassBlock.h"
#include "TorchBlock.h"

namespace cubz::game {
    ChunkMeshBuilder::ChunkMeshBuilder(const ChunkData& chunkData)
            : m_chunkData(chunkData) {
        m_blockRenderers.insert({ BlockType::air, std::make_shared<AirBlock>() });
        m_blockRenderers.insert({ BlockType::dirt, std::make_shared<DirtBlock>() });
        m_blockRenderers.insert({ BlockType::grass, std::make_shared<GrassBlock>() });
        m_blockRenderers.insert({ BlockType::torch, std::make_shared<TorchBlock>() });

        for (auto x = 0; x < CHUNK_SIZE; ++x) {
            for (auto y = 0; y < CHUNK_SIZE; ++y) {
                for (auto z = 0; z < CHUNK_SIZE; ++z) {
                    getBlock(x, y, z)->addToMesh(*this, x, y, z);
                }
            }
        }
    }

    Block* ChunkMeshBuilder::getBlockRenderer(cubz::game::BlockType type) {
        if (auto it = m_blockRenderers.find(type); it != m_blockRenderers.end()) {
            return it->second.get();
        } else {
            return m_blockRenderers[BlockType::air].get();
        }
    }

    Block* ChunkMeshBuilder::getBlock(int x, int y, int z) {
        return getBlockRenderer(m_chunkData.getBlock(x, y, z));
    }

    graphics::Mesh& ChunkMeshBuilder::getMesh() {
        return m_mesh;
    }
}