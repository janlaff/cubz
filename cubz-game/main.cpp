#include <core/Engine.h>
#include <utility/Log.h>
#include <graphics/Mesh.h>
#include <graphics/MeshRenderer.h>
#include <graphics/BasicComponents.h>
#include <graphics/ui/DebugView.h>


int main(int argc, char **argv) {
    auto engine = cubz::core::Engine();

    try {
        auto context = engine.createContext(800, 600, "Test Window");
        auto ecs = engine.createEntityComponentSystem();
        auto camera = engine.createCamera();
        auto resourceManager = engine.createResourceManager("./assets");
        auto meshRenderSystem = engine.createMeshRenderSystem();

        auto cube = ecs->createEntity();
        auto transform = cubz::graphics::Transform {
                { 0, 0, -1 },
                glm::mat4(1.0),
                { 1, 1, 1 },
        };

        //camera->lookAt({0, 0, -1});

        auto mesh = cubz::graphics::Mesh();
        const auto size = 10;
        mesh.addVertex({ -size, size, -size });
        mesh.addVertex({ size, size, -size });
        mesh.addVertex({ size, -size, -size });
        mesh.addVertex({ -size, -size, -size });
        mesh.addQuadTriangles();

        auto renderer = cubz::graphics::MeshRenderer(
            resourceManager->getShader("cube"),
            cubz::graphics::opengl::Material{
                resourceManager->getTexture("terrain.png"),
                { 1, 1, 1 },
                32
            });

        ecs->addComponent<cubz::graphics::Mesh>(cube, mesh);
        ecs->addComponent<cubz::graphics::Transform>(cube, transform);
        ecs->addComponent<cubz::graphics::MeshRenderer>(cube, renderer);

        context->setClearColor({ 1, 1, 1 });

        auto charMap = resourceManager->generateCharMap("OpenSans-Regular.ttf", 24);
        auto debugView = cubz::graphics::ui::DebugView(charMap);

        while (!context->windowClosed()) {
            context->clear();
            meshRenderSystem->update(context->getDeltaTime());
            debugView.update(context->getDeltaTime());
            debugView.render(*camera);
            meshRenderSystem->render(*camera);
            context->render();
        }
    } catch (std::exception& e) {
        cubz::utility::Log::error(e);
        return 1;
    }

    return 0;
}


/*#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <graphics/opengl/PointLight.h>
#include <graphics/opengl/DirectionalLight.h>
#include <graphics/opengl/Material.h>
#include <graphics/ui/DebugView.h>
#include <graphics/ui/FreetypeContext.h>
#include <graphics/ui/FreetypeText.h>
#include <graphics/Screen.h>
#include <utility/ConsoleLogger.h>
#include <utility/Log.h>

#include "DirtBlock.h"
#include "Skybox.h"
#include "Chunk.h"
#include "ResourceManager.h"
#include "World.h"

using namespace std::string_literals;

int main() {
    cubz::utility::Log::addLogger(std::make_shared<cubz::utility::ConsoleLogger>());
    auto& resourceManager = cubz::graphics::ResourceManager::getInstance();
    resourceManager.setAssetsDir("./assets");

    try {
        auto screen = cubz::graphics::opengl::Screen(1280, 800, "Cubz - Experimental Version");
        screen.getContext().setMouseEnabled(false);
        screen.getCamera().setPosition({ 0.0f, 1.0f, -2.0f });

        auto world = cubz::game::World();
        world.setBlock(cubz::game::BlockType::torch, 0, 0, 0);
        world.setBlock(cubz::game::BlockType::dirt, 2, 0, 1);

        auto charMap = resourceManager.generateCharMap("OpenSans-Regular.ttf", 24);
        auto debugView = cubz::graphics::ui::DebugView(charMap);

        auto chunkShader = resourceManager.getShader("chunk");

        auto dirLight = cubz::graphics::opengl::DirectionalLight {
            { 1.0f, -1.0f, 1.0f },
            glm::vec3(0.2f),
            glm::vec3(1.0f),
            glm::vec3(1.0f)
        };

        chunkShader.bind();
        dirLight.bind(chunkShader);
        chunkShader.setInt("blinn", true);
        chunkShader.unbind();

        while (!screen.shouldQuit()) {
            chunkShader.bind();
            chunkShader.setVec3("playerPosition", screen.getCamera().getPosition());
            chunkShader.unbind();
            world.setPlayerPosition(screen.getCamera().getPosition());

            screen.clear();

            world.update();
            debugView.update();

            world.render(screen.getCamera());
            debugView.render(screen.getCamera());
            screen.render();

            screen.processInput();
        }
    } catch (std::exception &e) {
        cubz::utility::Log::error(e);
    }

    return 0;
}*/