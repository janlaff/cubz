#pragma once

#include <core/MeshRenderSystem.h>
#include <SystemManager.h>
#include <Camera.h>

namespace cubz::game {
    class ChunkRenderSystem : public core::MeshRenderSystem {
    public:
        using core::MeshRenderSystem::MeshRenderSystem;

        void update(float deltaTime) override;

    private:

    };
}