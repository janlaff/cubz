#pragma once

#include "SystemManager.h"
#include "Camera.h"
#include "EntityComponentSystem.h"

namespace cubz::core {
    class MeshRenderSystem : public ecs::System {
    public:
        using ecs::System::System;

        virtual void update(float deltaTime);
        virtual void render(const graphics::Camera& camera);
    };
}