#pragma once

#include "SystemManager.h"
#include "Camera.h"

namespace cubz::core {
    class MeshRenderSystem : public cubz::ecs::System {
    public:
        using ecs::System::System;

        void update(float deltaTime);
        void render(const cubz::graphics::Camera& camera);
    };
}