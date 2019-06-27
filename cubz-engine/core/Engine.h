#pragma once

#include <memory>

#include "EntityComponentSystem.h"
#include "opengl/Context.h"
#include "ResourceManager.h"
#include "Camera.h"
#include "MeshRenderSystem.h"

namespace cubz::core {
    class Engine {
    public:
        Engine();

        std::shared_ptr<MeshRenderSystem> createMeshRenderSystem();
        std::shared_ptr<graphics::ResourceManager> createResourceManager(const std::string& assetsDir);
        std::shared_ptr<ecs::EntityComponentSystem> createEntityComponentSystem();
        std::shared_ptr<graphics::Camera> createCamera();
        std::shared_ptr<graphics::opengl::Context> createContext(int width, int height, std::string title);
        std::shared_ptr<graphics::opengl::Context> getContext();
        std::shared_ptr<ecs::EntityComponentSystem> getEntityComponentSystem();

    private:
        std::shared_ptr<ecs::EntityComponentSystem> m_ecs;
        std::shared_ptr<graphics::opengl::Context> m_context;
        std::shared_ptr<graphics::Camera> m_camera;
        std::shared_ptr<graphics::ResourceManager> m_resourceManager;
        std::shared_ptr<MeshRenderSystem> m_meshRenderSystem;
        float m_deltaTime;
        float m_lastFrame;
    };
}