#pragma once

#include <ecs/SystemManager.h>
#include <graphics/Camera.h>


namespace cubz::game {
    class ChunkUpdateSystem : public ecs::System {
    public:
        using ecs::System::System;

        void updateChunks();
    };
}