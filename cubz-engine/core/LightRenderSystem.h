#pragma once

#include "ResourceManager.h"
#include "EntityComponentSystem.h"
#include "DirectionalLight.h"

namespace cubz::core {
    class LightRenderSystem : public ecs::System {
    public:
        LightRenderSystem(ecs::EntityComponentSystem* ecs, graphics::ResourceManager* rsc, graphics::DirectionalLight sunLight);

        void update(const glm::vec3& playerPosition, bool sunOn);

    private:
        graphics::ResourceManager* m_rsc;
        graphics::DirectionalLight m_sunLight;
    };
}