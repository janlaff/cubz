#pragma once

#include <ecs/EntityComponentSystem.h>
#include <graphics/Camera.h>

namespace cubz::game {
    class TorchRenderSystem : public ecs::System {
    public:
        using System::System;

        void update();
        void render(const graphics::Camera& camera);
    };
}