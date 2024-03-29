#include "BasicComponents.h"
#include "LightRenderSystem.h"
#include "PointLight.h"

namespace cubz::core {
    LightRenderSystem::LightRenderSystem(cubz::ecs::EntityComponentSystem *ecs, cubz::graphics::ResourceManager *rsc, graphics::DirectionalLight sunLight)
            : ecs::System(ecs)
            , m_rsc(rsc)
            , m_sunLight(std::move(sunLight)) {
        for (auto [name, shader] : m_rsc->getShaders()) {
            shader.bind();
            m_sunLight.bind(shader);
            shader.unbind();
        }
    }

    void LightRenderSystem::update(const glm::vec3& playerPosition, bool sunOn) {
        std::vector<graphics::PointLight> pointLights;

        for (const auto& entity : m_updatedEntities) {
            auto light = m_ecs->getComponent<graphics::PointLight>(entity);
            light.position = m_ecs->getComponent<graphics::Transform>(entity).position;
            pointLights.push_back(std::move(light));
        }

        for (auto [name, shader] : m_rsc->getShaders()) {
            shader.bind();

            int lightIndex = 0;

            for (auto& pointLight : pointLights) {
                pointLight.bind(shader, lightIndex++);
            }

            shader.setInt("lightCount", lightIndex + 1);
            shader.setVec3("playerPosition", playerPosition);
            shader.setInt("dirLight.isActive", sunOn);

            shader.unbind();
        }

        m_updatedEntities.clear();
    }
}