#pragma once

#include <core/GameObject.h>

#include "WorldPos.h"

namespace cubz::game {
    class TorchEntity : public core::GameObject {
    public:
        TorchEntity(core::Engine* engine, const WorldPos& position);

        void update(float deltaTime) override;
    };
}