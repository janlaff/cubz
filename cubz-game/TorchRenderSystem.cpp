#include "TorchRenderSystem.h"
#include "TorchRenderer.h"

namespace cubz::game {
    void TorchRenderSystem::update() {
        for (const auto& entity : m_updatedEntities) {
            const auto& transform = m_ecs->getComponent<graphics::Transform>(entity);
            const auto& mesh = m_ecs->getComponent<graphics::Mesh>(entity);
            auto& torchRenderer = m_ecs->getComponent<TorchRenderer>(entity);

            torchRenderer.update(transform, mesh);
        }
    }

    void TorchRenderSystem::render(const cubz::graphics::Camera &camera) {
        for (const auto& entity : m_entities) {
            auto& torchRenderer = m_ecs->getComponent<TorchRenderer>(entity);
            torchRenderer.render(camera);
        }
    }
}