#include <core/Engine.h>
#include <utility/Log.h>
#include <graphics/Mesh.h>
#include <graphics/MeshRenderer.h>
#include <graphics/BasicComponents.h>
#include <graphics/ui/DebugView.h>
#include <glm/gtc/matrix_transform.hpp>

#include "Block.h"


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
                { 0, 0, 0 },
                glm::mat4(1.0f),
                { 1, 1, 1 },
        };

        camera->setPosition({ 0, 2, 0 });
        camera->setDirection({ 0, -1, 0 });

        auto mesh = cubz::graphics::Mesh();
        cubz::game::Block block;
        block.addSomeStuff(mesh);

        auto renderer = cubz::graphics::MeshRenderer(
            resourceManager->getShader("mesh"),
            cubz::graphics::opengl::Material{
                resourceManager->getTexture("terrain.png"),
                { 1, 1, 1 },
                32
            });

        ecs->addComponent<cubz::graphics::Mesh>(cube, mesh);
        ecs->addComponent<cubz::graphics::Transform>(cube, transform);
        ecs->addComponent<cubz::graphics::MeshRenderer>(cube, renderer);

        context->setClearColor({0, 0, 0});

        while (!context->windowClosed()) {
            context->clear();
            meshRenderSystem->update(context->getDeltaTime());
            meshRenderSystem->render(*camera);
            context->render();
        }
    } catch (std::exception& e) {
        cubz::utility::Log::error(e);
        return 1;
    }

    return 0;
}