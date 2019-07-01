#include "MeshRenderSystem.h"
#include "EntityComponentSystem.h"
#include "Mesh.h"
#include "BasicComponents.h"
#include "MeshRenderer.h"

namespace cubz::core {
    void MeshRenderSystem::update(float deltaTime) {
        for (const auto& entity : m_updatedEntities) {
            const auto& transform = m_ecs->getComponent<cubz::graphics::Transform>(entity);
            auto& mesh = m_ecs->getComponent<cubz::graphics::Mesh>(entity);
            auto& meshRenderer = m_ecs->getComponent<cubz::graphics::MeshRenderer>(entity);

            meshRenderer.update(transform, mesh);
        }

        m_updatedEntities.clear();
    }

    void MeshRenderSystem::render(const cubz::graphics::Camera& camera) {
        for (const auto& entity : m_entities) {
            auto& meshRenderer = m_ecs->getComponent<cubz::graphics::MeshRenderer>(entity);
            meshRenderer.render(camera);
        }
    }
}