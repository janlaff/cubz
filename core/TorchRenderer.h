#pragma once

#include <unordered_map>

#include "MeshRenderer.h"
#include "WorldPos.h"
#include "opengl/PointLight.h"

namespace core {
    class TorchRenderer : public MeshRenderer {
    public:
        void render(const Camera& camera, const glm::vec3& position) override;
    };
}