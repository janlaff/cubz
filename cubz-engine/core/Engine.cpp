#include "Engine.h"
#include "Log.h"
#include "ConsoleLogger.h"

#include "Mesh.h"
#include "MeshRenderer.h"
#include "BasicComponents.h"

namespace cubz::core {
    Engine::Engine() {
        utility::Log::addLogger(std::make_shared<utility::ConsoleLogger>());
    }

    std::shared_ptr<MeshRenderSystem> Engine::createMeshRenderSystem() {
        // Register needed components
        m_ecs->registerComponent<graphics::Transform>();
        m_ecs->registerComponent<graphics::Mesh>();
        m_ecs->registerComponent<graphics::MeshRenderer>();
        // Create render system
        m_meshRenderSystem = m_ecs->registerSystem<MeshRenderSystem>();

        cubz::ecs::Signature renderSignature;
        renderSignature.set(m_ecs->getComponentType<cubz::graphics::Mesh>());
        renderSignature.set(m_ecs->getComponentType<cubz::graphics::MeshRenderer>());
        renderSignature.set(m_ecs->getComponentType<cubz::graphics::Transform>());
        m_ecs->setSystemSignature<MeshRenderSystem>(renderSignature);

        return m_meshRenderSystem;
    }

    std::shared_ptr<graphics::ResourceManager> Engine::createResourceManager(const std::string &assetsDir) {
        m_resourceManager = std::make_shared<graphics::ResourceManager>(assetsDir);
        return m_resourceManager;
    }

    std::shared_ptr<ecs::EntityComponentSystem> Engine::createEntityComponentSystem() {
        m_ecs = std::make_shared<ecs::EntityComponentSystem>();
        return m_ecs;
    }

    std::shared_ptr<graphics::Camera> Engine::createCamera() {
        m_camera = std::make_shared<graphics::Camera>(m_context->getWindowWidth(), m_context->getWindowHeight());
        return m_camera;
    }

    std::shared_ptr<graphics::opengl::Context> Engine::createContext(int width, int height, std::string title) {
        m_context = std::make_shared<graphics::opengl::Context>(width, height, title);
        return m_context;
    }

    std::shared_ptr<graphics::opengl::Context> Engine::getContext() {
        return m_context;
    }

    std::shared_ptr<ecs::EntityComponentSystem> Engine::getEntityComponentSystem() {
        return m_ecs;
    }
}