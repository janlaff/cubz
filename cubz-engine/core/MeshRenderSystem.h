#pragma once

#include "Camera.h"
#include "EntityComponentSystem.h"

namespace cubz::core {
    class MeshRenderSystem : public ecs::System {
    public:
        using System::System;

        virtual void update(float deltaTime);
        virtual void render(const graphics::Camera& camera);
    };
}