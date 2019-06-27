#pragma once

#include "ecs/EntityComponentSystem.h"
#include "physics/PhysicEngine.h"
#include "core/RenderEngine.h"

namespace cubz::graphics {
    class Engine {
    public:
        Engine()

    private:
        EntityComponentSystem m_ecs;
    };
}