#include "ChunkUpdateSystem.h"
#include "ChunkData.h"
#include "Block.h"

#include <graphics/BasicComponents.h>
#include <graphics/MeshRenderer.h>
#include <ecs/EntityComponentSystem.h>

namespace cubz::game {
    void ChunkUpdateSystem::updateChunks() {
        for (const auto& entity : m_updatedEntities) {
            auto& mesh = m_ecs->getComponent<cubz::graphics::Mesh>(entity);
            auto& chunkData = m_ecs->getComponent<ChunkData>(entity);

            mesh.vertices.clear();
            mesh.triangles.clear();
            mesh.normals.clear();
            mesh.uvs.clear();

            for (int x = 0; x < CHUNK_SIZE; ++x) {
                for (int y = 0; y < CHUNK_SIZE; ++y) {
                    for (int z = 0; z < CHUNK_SIZE; ++z) {
                        auto blockType = chunkData.getBlock(x, y, z);

                        if (blockType != BlockType::air) {
                            Block block;
                            block.addSolid(mesh, x, y, z);
                        }
                        //m_blockBuilders[blockType].addToMesh(chunkData)
                    }
                }
            }
        }
    }
}