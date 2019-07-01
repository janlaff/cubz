#include "SkyboxRenderSystem.h"
#include "SkyboxRenderer.h"

namespace cubz::core {
    void SkyboxRenderSystem::render(const graphics::Camera& camera, const glm::vec3& playerPosition) {
        // Should only be one!
        for (const auto& entity : m_entities) {
            auto& skyboxRenderer = m_ecs->getComponent<cubz::graphics::SkyboxRenderer>(entity);
            skyboxRenderer.render(camera, playerPosition);
        }
    }
}