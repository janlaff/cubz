#include "ChunkUpdateSystem.h"
#include "ChunkData.h"
#include "Block.h"
#include "ChunkMeshBuilder.h"

#include <graphics/BasicComponents.h>
#include <graphics/MeshRenderer.h>
#include <ecs/EntityComponentSystem.h>

namespace cubz::game {
    void ChunkUpdateSystem::updateChunks() {
        for (const auto& entity : m_updatedEntities) {
            auto& mesh = m_ecs->getComponent<graphics::Mesh>(entity);
            auto& chunkData = m_ecs->getComponent<ChunkData>(entity);
            auto& transform = m_ecs->getComponent<graphics::Transform>(entity);

            auto chunkMeshBuilder = ChunkMeshBuilder(chunkData);

            mesh = chunkMeshBuilder.getMesh();

            transform.position = chunkData.getPosition().toVec();
        }

        m_updatedEntities.clear();
    }
}