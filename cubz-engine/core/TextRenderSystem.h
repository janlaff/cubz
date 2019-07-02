#pragma once

#include "ui/FreetypeCharMap.h"
#include "EntityComponentSystem.h"
#include "Camera.h"

namespace cubz::core {
    class TextRenderSystem : public ecs::System {
    public:
        using System::System;

        void update();
        void render(const graphics::Camera& camera, const graphics::ui::FreetypeCharMap& charMap);
    };
}