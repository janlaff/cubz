#pragma once

#include <core/GameObject.h>
#include "ChunkData.h"

namespace cubz::game {
    class ChunkEntity : public core::GameObject {
    public:
        ChunkEntity(core::Engine* engine);

        void update(float deltaTime) override;
    };
}