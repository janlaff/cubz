#pragma once

#include <unordered_map>

#include "MeshRenderer.h"
#include "WorldPos.h"
#include "graphics/PointLight.h"

namespace cubz::game {
    struct TorchRenderer : graphics::MeshRenderer {
        using MeshRenderer::MeshRenderer;

        void render(const graphics::Camera& camera) override;
    };
}