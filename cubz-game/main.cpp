#include <core/Engine.h>
#include <utility/Log.h>
#include <graphics/Mesh.h>
#include <graphics/MeshRenderer.h>
#include <graphics/BasicComponents.h>
#include <graphics/ui/DebugView.h>
#include <glm/gtc/matrix_transform.hpp>

#include "ChunkUpdateSystem.h"
#include "World.h"
#include "ChunkEntity.h"

int main(int argc, char **argv) {
    try {
        auto engine = cubz::core::Engine(800, 600, "Test Window", "./assets");

        auto& context = engine.getContext();
        auto& ecs = engine.getECS();
        auto& camera = engine.getCamera();
        auto& resourceManager = engine.getResourceManager();

        ecs.registerComponent<cubz::graphics::Transform>();
        ecs.registerComponent<cubz::graphics::MeshRenderer>();
        ecs.registerComponent<cubz::graphics::Mesh>();
        ecs.registerComponent<cubz::game::ChunkData>();

        // Register chunk update system
        auto chunkUpdateSystem = ecs.registerSystem<cubz::game::ChunkUpdateSystem>();
        auto signature = cubz::ecs::Signature();
        signature.set(ecs.getComponentType<cubz::game::ChunkData>());
        signature.set(ecs.getComponentType<cubz::graphics::Mesh>());
        signature.set(ecs.getComponentType<cubz::graphics::Transform>());
        ecs.setSystemSignature<cubz::game::ChunkUpdateSystem>(signature);

        auto meshRenderSystem = ecs.registerSystem<cubz::core::MeshRenderSystem>();
        signature = cubz::ecs::Signature();
        signature.set(ecs.getComponentType<cubz::graphics::Transform>());
        signature.set(ecs.getComponentType<cubz::graphics::MeshRenderer>());
        signature.set(ecs.getComponentType<cubz::graphics::Mesh>());
        ecs.setSystemSignature<cubz::core::MeshRenderSystem>(signature);

        cubz::game::World world(&engine);

        context.setClearColor({0, 0, 0});

        camera.setPosition(glm::vec3 { 1, 0, 0 } * 10.0f);
        camera.lookAt({ 0, -16, 0 });

        int i = 0;
        float deltaSum = 0;
        int fpsFrequency = 500;

        while (!context.windowClosed()) {
            float deltaTime = context.getDeltaTime();

            deltaSum += deltaTime;

            if (i++ == fpsFrequency) {
                float averageDeltaTime = deltaSum / fpsFrequency;
                int fps = 1.0f / averageDeltaTime;

                cubz::utility::Log::debug("Fps: " + std::to_string(fps));

                i = 0;
                deltaSum = 0;
            }

            context.clear();
            chunkUpdateSystem->updateChunks();
            meshRenderSystem->update(deltaTime);
            meshRenderSystem->render(camera);
            context.render();
        }
    } catch (std::exception& e) {
        cubz::utility::Log::error(e);
        return 1;
    }

    return 0;
}