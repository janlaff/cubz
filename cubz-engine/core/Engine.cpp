#include "Engine.h"
#include "Log.h"
#include "ConsoleLogger.h"

#include "Mesh.h"
#include "MeshRenderer.h"
#include "BasicComponents.h"

namespace cubz::core {
    Engine::Engine(int width, int height, std::string title, std::string assetsDir)
            : m_context(width, height, title)
            , m_camera(width, height)
            , m_resourceManager(assetsDir) {
        utility::Log::addLogger(std::make_shared<utility::ConsoleLogger>());
    }

    graphics::Camera& Engine::getCamera() {
        return m_camera;
    }

    graphics::ResourceManager& Engine::getResourceManager() {
        return m_resourceManager;
    }

    graphics::opengl::Context& Engine::getContext() {
        return m_context;
    }

    ecs::EntityComponentSystem& Engine::getECS() {
        return m_ecs;
    }
}