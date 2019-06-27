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
        Engine(int width, int height, std::string title, std::string assetsDir);

        graphics::Camera& getCamera();
        graphics::ResourceManager& getResourceManager();
        graphics::opengl::Context& getContext();
        ecs::EntityComponentSystem& getECS();

    private:
        ecs::EntityComponentSystem m_ecs;
        graphics::opengl::Context m_context;
        graphics::Camera m_camera;
        graphics::ResourceManager m_resourceManager;
        float m_deltaTime;
        float m_lastFrame;
    };
}