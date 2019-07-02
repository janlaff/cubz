#pragma once

#include "Engine.h"
#include "MeshRenderSystem.h"
#include "TextRenderSystem.h"
#include "LightRenderSystem.h"
#include "SkyboxRenderSystem.h"

namespace cubz::core {
    class DefaultSystems {
    public:
        DefaultSystems(Engine* engine);

        std::shared_ptr<MeshRenderSystem> createMeshRenderSystem();
        std::shared_ptr<TextRenderSystem> createTextRenderSystem();
        std::shared_ptr<LightRenderSystem> createLightRenderSystem(const graphics::DirectionalLight& sun);
        std::shared_ptr<SkyboxRenderSystem> createSkyboxRenderSystem();

    private:
        Engine* m_engine;
    };
}