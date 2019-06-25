#include <utility>

#include "Chunk.h"
#include "Block.h"
#include "AirBlock.h"
#include "GrassBlock.h"
#include "World.h"

namespace core {
    Chunk::Chunk(World* world, const WorldPos& position)
        : m_position(position)
        , m_update(true)
        , m_world(world) {
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
        m_update = true;
    }

    void Chunk::update() {
        if (!m_update) return;

        auto& meshData = m_chunkRenderer.getMeshData();

        meshData.vertices.clear();
        meshData.triangles.clear();
        meshData.normals.clear();
        meshData.uvs.clear();

        for (int x = 0; x < chunkSize; ++x) {
            for (int y = 0; y < chunkSize; ++y) {
                for (int z = 0; z < chunkSize; ++z) {
                    m_blocks[x][y][z]->addToMesh(*this, x, y, z, meshData);
                }
            }
        }

        m_chunkRenderer.update();
        m_update = false;
    }

    void Chunk::render(const core::Camera &camera) {
        m_chunkRenderer.render(camera, m_position.toVec());
    }

    std::shared_ptr<Block> Chunk::getBlock(int x, int y, int z) const {
        if (inRange(x) && inRange(y) && inRange(z)) {
            return m_blocks[x][y][z];
        } else {
            return m_world->getBlock(m_position.x + x, m_position.y + y, m_position.z + z);
        }
    }

    const WorldPos& Chunk::getPosition() const {
        return m_position;
    }

    bool Chunk::inRange(int index) const {
        return !(index < 0 || index >= chunkSize);
    }
}