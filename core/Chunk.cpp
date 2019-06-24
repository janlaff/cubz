#include <utility>

#include "Chunk.h"
#include "Block.h"
#include "AirBlock.h"

namespace core {
    Chunk::Chunk(const glm::vec3& position)
        : m_position(position) {
        for (int x = 0; x < chunkSize; ++x) {
            for (int y = 0; y < chunkSize; ++y) {
                for (int z = 0; z < chunkSize; ++z) {
                    m_blocks[x][y][z] = std::make_shared<AirBlock>();
                }
            }
        }
    }

    void Chunk::setBlock(std::shared_ptr<core::Block> block, int x, int y, int z) {
        m_blocks[x][y][z] = std::move(block);
    }

    void Chunk::update() {
        auto& meshData = m_chunkRenderer.getMeshData();

        meshData.vertices.clear();
        meshData.triangles.clear();
        meshData.uvs.clear();

        for (int x = 0; x < chunkSize; ++x) {
            for (int y = 0; y < chunkSize; ++y) {
                for (int z = 0; z < chunkSize; ++z) {
                    m_blocks[x][y][z]->addToMesh(*this, x, y, z, meshData);
                }
            }
        }

        m_chunkRenderer.update();
    }

    void Chunk::render(const core::Camera &camera) {
        m_chunkRenderer.render(camera, m_position);
    }

    std::shared_ptr<Block> Chunk::getBlock(int x, int y, int z) const {
        if (x < 0 || x >= chunkSize) return std::make_shared<AirBlock>();
        if (y < 0 || y >= chunkSize) return std::make_shared<AirBlock>();
        if (z < 0 || z >= chunkSize) return std::make_shared<AirBlock>();

        return m_blocks[x][y][z];
    }
}