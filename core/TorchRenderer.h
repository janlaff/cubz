#pragma once

#include <unordered_map>

#include "Renderer.h"
#include "WorldPos.h"
#include "opengl/PointLight.h"

namespace core {
    class TorchRenderer : public Renderer {
    public:
        void render(const Camera& camera, const glm::vec3& position) override;
        void clearTorchs();
        void addTorch(const WorldPos& position);
        void removeTorch(const WorldPos& position);

    private:
        std::unordered_map<WorldPos, core::opengl::PointLight, WorldPosHash> m_lights;
    };
}