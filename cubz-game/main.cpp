#include <core/Engine.h>
#include <utility/Log.h>
#include <graphics/Mesh.h>
#include <graphics/MeshRenderer.h>
#include <graphics/BasicComponents.h>
#include <graphics/ui/DebugView.h>
#include <glm/gtc/matrix_transform.hpp>

#include "ChunkRenderSystem.h"
#include "World.h"

int main(int argc, char **argv) {
    try {
        auto engine = cubz::core::Engine(800, 600, "Test Window", "./assets");

        auto& context = engine.getContext();
        auto& ecs = engine.getECS();
        auto& camera = engine.getCamera();
        auto& resourceManager = engine.getResourceManager();

        // Register chunk components
        ecs.registerComponent<cubz::game::ChunkData>();
        ecs.registerComponent<cubz::graphics::MeshRenderer>();
        ecs.registerComponent<cubz::graphics::Mesh>();

        // Register chunk rendering system
        auto chunkRenderSystem = ecs.registerSystem<cubz::game::ChunkRenderSystem>();
        auto signature = cubz::ecs::Signature();
        signature.set(ecs.getComponentType<cubz::game::ChunkData>());
        signature.set(ecs.getComponentType<cubz::graphics::MeshRenderer>());
        signature.set(ecs.getComponentType<cubz::graphics::Mesh>());
        ecs.setSystemSignature<cubz::game::ChunkRenderSystem>(signature);

        /*auto chunk = ecs.createEntity();
        auto meshRenderer = cubz::graphics::MeshRenderer(
                resourceManager.getShader("mesh"),
                cubz::graphics::opengl::Material{
                        resourceManager.getTexture("terrain.png"),
                        { 1, 1, 1 },
                        32
                });
        auto mesh = cubz::graphics::Mesh();
        auto chunkData = cubz::game::ChunkData();
        chunkData.

        ecs.addComponent<cubz::graphics::Mesh>(chunk, mesh);
        ecs.addComponent<cubz::graphics::MeshRenderer>(chunk, meshRenderer);
        ecs.addComponent<cubz::game::ChunkData>(chunk, chunkData);*/


        cubz::game::World world(&engine);

        context.setClearColor({0, 0, 0});

        camera.setPosition(glm::vec3 { 4, 3, 4 } * 10.0f);
        camera.lookAt({ 0, 0, 0 });

        int i = 0;

        while (!context.windowClosed()) {
            float deltaTime = context.getDeltaTime();
            int fps = 1.0f / deltaTime;

            if (i++ == 10) {
                i = 0;

                cubz::utility::Log::debug("Fps: " + std::to_string(fps));
            }

            context.clear();
            chunkRenderSystem->update(deltaTime);
            chunkRenderSystem->render(camera);
            context.render();
        }
    } catch (std::exception& e) {
        cubz::utility::Log::error(e);
        return 1;
    }

    return 0;
}