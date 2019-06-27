#include <utility>

#include "Chunk.h"
#include "Block.h"
#include "AirBlock.h"
#include "GrassBlock.h"
#include "DirtBlock.h"
#include "TorchBlock.h"
#include "World.h"

namespace cubz::game {
    Chunk::Chunk(World* world, const WorldPos& position)
        : m_update(true)
        , m_world(world) {
        for (int x = 0; x < chunkSize; ++x) {
            for (int y = 0; y < chunkSize; ++y) {
                for (int z = 0; z < chunkSize; ++z) {
                    m_blocks[x][y][z] = BlockType::air;
                }
            }
        }
    }

    void Chunk::setBlockType(BlockType block, int x, int y, int z) {
        /*if (m_blocks[x][y][z] == BlockType::torch) {
            m_world->removeLight({ m_position.x + x, m_position.y + y, m_position.z + z });
        }

        if (block == BlockType::torch) {
            m_world->addLight({ m_position.x + x, m_position.y + y, m_position.z + z });
        }*/

        m_blocks[x][y][z] = block;
        m_update = true;
    }

    BlockType Chunk::getBlockType(int x, int y, int z) const {
        return m_blocks[x][y][z];
    }

    void Chunk::update() {
        if (!m_update) return;

        auto meshData = graphics::Mesh();
        //auto& torchMeshData = m_torchRenderer.getMeshData();


        meshData.vertices.clear();
        meshData.triangles.clear();
        meshData.normals.clear();
        meshData.uvs.clear();
        /*torchMeshData.vertices.clear();
        torchMeshData.triangles.clear();
        torchMeshData.normals.clear();
        torchMeshData.uvs.clear();*/

        for (int x = 0; x < chunkSize; ++x) {
            for (int y = 0; y < chunkSize; ++y) {
                for (int z = 0; z < chunkSize; ++z) {
                    if (getBlockType(x, y, z) == BlockType::torch) {
                        //getBlock(x, y, z)->addToMesh(*this, x, y, z, torchMeshData);
                    } else {
                        getBlock(x, y, z)->addToMesh(*this, x, y, z, meshData);
                    }
                }
            }
        }

        m_chunkRenderer.update(m_transform, meshData);
        /*m_chunkRenderer.updateLights(m_world->getLights());
        m_torchRenderer.update();*/

        m_update = false;
    }

    void Chunk::render(const graphics::Camera &camera) {
        //m_torchRenderer.render(camera, m_position.toVec());
        m_chunkRenderer.render(camera);
    }

    std::shared_ptr<Block> Chunk::getBlock(int x, int y, int z) const {
        if (inRange(x) && inRange(y) && inRange(z)) {
            switch (getBlockType(x, y, z)) {
                case BlockType::air:
                    return std::make_shared<AirBlock>();
                case BlockType::grass:
                    return std::make_shared<GrassBlock>();
                case BlockType::dirt:
                    return std::make_shared<DirtBlock>();
                case BlockType::torch:
                    return std::make_shared<TorchBlock>();
                default:
                    return std::make_shared<AirBlock>();
            }
        } else {
            return m_world->getBlock(m_transform.position.x + x, m_transform.position.y + y, m_transform.position.z + z);
        }
    }

    const WorldPos& Chunk::getPosition() const {
        auto pos = m_transform.position;
        return WorldPos { int(pos.x), int(pos.y), int(pos.z) };
    }

    bool Chunk::inRange(int index) const {
        return !(index < 0 || index >= chunkSize);
    }
}