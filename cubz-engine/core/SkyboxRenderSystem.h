#pragma once

#include "Camera.h"
#include "EntityComponentSystem.h"

namespace cubz::core {
    class SkyboxRenderSystem : public ecs::System {
    public:
        using ecs::System::System;

        virtual void render(const graphics::Camera& camera);
    };
}