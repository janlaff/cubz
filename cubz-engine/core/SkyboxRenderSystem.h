#pragma once

#include "Camera.h"
#include "EntityComponentSystem.h"

namespace cubz::core {
    class SkyboxRenderSystem : public ecs::System {
    public:
        using System::System;

        virtual void render(const graphics::Camera& camera, const glm::vec3& playerPosition, float ambient);
    };
}