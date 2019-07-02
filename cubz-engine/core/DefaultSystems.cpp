#include <SkyboxRenderer.h>
#include "DefaultSystems.h"

#include "BasicComponents.h"
#include "MeshRenderer.h"
#include "Mesh.h"
#include "ui/TextData.h"
#include "ui/TextRenderer.h"
#include "SkyboxRenderer.h"

namespace cubz::core {
    DefaultSystems::DefaultSystems(Engine *engine) : m_engine(engine) {}

    std::shared_ptr<MeshRenderSystem> DefaultSystems::createMeshRenderSystem() {
        m_engine->getECS().registerComponent<graphics::Transform>();
        m_engine->getECS().registerComponent<graphics::MeshRenderer>();
        m_engine->getECS().registerComponent<graphics::Mesh>();

        auto meshRenderSystem = m_engine->getECS().registerSystem<MeshRenderSystem>();
        auto signature = cubz::ecs::Signature();
        signature.set(m_engine->getECS().getComponentType<graphics::Transform>());
        signature.set(m_engine->getECS().getComponentType<graphics::MeshRenderer>());
        signature.set(m_engine->getECS().getComponentType<graphics::Mesh>());
        m_engine->getECS().setSystemSignature<MeshRenderSystem>(signature);

        return meshRenderSystem;
    }

    std::shared_ptr<TextRenderSystem> DefaultSystems::createTextRenderSystem() {
        m_engine->getECS().registerComponent<graphics::ui::TextData>();
        m_engine->getECS().registerComponent<graphics::ui::TextRenderer>();

        auto textRenderSystem = m_engine->getECS().registerSystem<TextRenderSystem>();
        auto signature = cubz::ecs::Signature();
        signature.set(m_engine->getECS().getComponentType<graphics::ui::TextData>());
        signature.set(m_engine->getECS().getComponentType<graphics::ui::TextRenderer>());
        m_engine->getECS().setSystemSignature<TextRenderSystem>(signature);

        return textRenderSystem;
    }

    std::shared_ptr<LightRenderSystem> DefaultSystems::createLightRenderSystem(const graphics::DirectionalLight &sun) {
        m_engine->getECS().registerComponent<graphics::PointLight>();
        m_engine->getECS().registerComponent<graphics::Transform>();

        auto lightRenderSystem = m_engine->getECS().registerSystem<LightRenderSystem>(&m_engine->getResourceManager(), sun);
        auto signature = cubz::ecs::Signature();
        signature.set(m_engine->getECS().getComponentType<graphics::PointLight>());
        signature.set(m_engine->getECS().getComponentType<graphics::Transform>());
        m_engine->getECS().setSystemSignature<LightRenderSystem>(signature);

        return lightRenderSystem;
    }

    std::shared_ptr<SkyboxRenderSystem> DefaultSystems::createSkyboxRenderSystem() {
        m_engine->getECS().registerComponent<graphics::SkyboxRenderer>();

        auto skyboxRenderSystem = m_engine->getECS().registerSystem<cubz::core::SkyboxRenderSystem>();
        auto signature = cubz::ecs::Signature();
        signature.set(m_engine->getECS().getComponentType<graphics::SkyboxRenderer>());
        m_engine->getECS().setSystemSignature<cubz::core::SkyboxRenderSystem>(signature);

        return skyboxRenderSystem;
    }
}