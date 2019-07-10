#pragma once

#include <core/GameObject.h>

#include "WorldPos.h"

namespace cubz::game {
    class Torch : public core::GameObject {
    public:
        Torch(core::Engine* engine, const WorldPos& position);

        void update(float deltaTime) override;
    };
}