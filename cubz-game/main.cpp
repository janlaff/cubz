#include <core/Engine.h>
#include <utility/Log.h>
#include <graphics/Mesh.h>
#include <graphics/MeshRenderer.h>
#include <graphics/BasicComponents.h>
#include <graphics/ui/DebugView.h>
#include <glm/gtc/matrix_transform.hpp>
#include <core/LightRenderSystem.h>
#include <core/SkyboxRenderSystem.h>
#include <graphics/SkyboxRenderer.h>
#include <core/Player.h>

#include "ChunkUpdateSystem.h"
#include "World.h"
#include "ChunkEntity.h"
#include "TorchRenderer.h"
#include "TorchRenderSystem.h"

int main(int argc, char **argv) {
    try {
        auto engine = cubz::core::Engine(1280, 800, "Test Window", "./assets");

        auto& context = engine.getContext();
        auto& ecs = engine.getECS();
        auto& camera = engine.getCamera();
        auto& resourceManager = engine.getResourceManager();

        ecs.registerComponent<cubz::graphics::Transform>();
        ecs.registerComponent<cubz::graphics::MeshRenderer>();
        ecs.registerComponent<cubz::graphics::PointLight>();
        ecs.registerComponent<cubz::graphics::Mesh>();
        ecs.registerComponent<cubz::graphics::SkyboxRenderer>();
        ecs.registerComponent<cubz::game::ChunkData>();
        ecs.registerComponent<cubz::game::TorchRenderer>();

        // Register chunk update system
        auto chunkUpdateSystem = ecs.registerSystem<cubz::game::ChunkUpdateSystem>();
        auto signature = cubz::ecs::Signature();
        signature.set(ecs.getComponentType<cubz::game::ChunkData>());
        signature.set(ecs.getComponentType<cubz::graphics::Mesh>());
        signature.set(ecs.getComponentType<cubz::graphics::Transform>());
        ecs.setSystemSignature<cubz::game::ChunkUpdateSystem>(signature);

        // Mesh rendering system
        auto meshRenderSystem = ecs.registerSystem<cubz::core::MeshRenderSystem>();
        signature = cubz::ecs::Signature();
        signature.set(ecs.getComponentType<cubz::graphics::Transform>());
        signature.set(ecs.getComponentType<cubz::graphics::MeshRenderer>());
        signature.set(ecs.getComponentType<cubz::graphics::Mesh>());
        ecs.setSystemSignature<cubz::core::MeshRenderSystem>(signature);

        // Skybox rendering system
        auto skyboxRenderSystem = ecs.registerSystem<cubz::core::SkyboxRenderSystem>();
        signature = cubz::ecs::Signature();
        signature.set(ecs.getComponentType<cubz::graphics::SkyboxRenderer>());
        ecs.setSystemSignature<cubz::core::SkyboxRenderSystem>(signature);

        // Torch rendering system
        auto torchRenderSystem = ecs.registerSystem<cubz::game::TorchRenderSystem>();
        signature = cubz::ecs::Signature();
        signature.set(ecs.getComponentType<cubz::graphics::Mesh>());
        signature.set(ecs.getComponentType<cubz::graphics::Transform>());
        signature.set(ecs.getComponentType<cubz::game::TorchRenderer>());
        ecs.setSystemSignature<cubz::game::TorchRenderSystem>(signature);

        // Light rendering system
        // Create sun
        auto sun = cubz::graphics::DirectionalLight {
            { 1.0f, -1.0f, 1.0f },
            glm::vec3(0.2f),
            glm::vec3(1.0f),
            glm::vec3(1.0f)
        };

        auto lightRenderSystem = ecs.registerSystem<cubz::core::LightRenderSystem>(&resourceManager, &sun);
        signature = cubz::ecs::Signature();
        signature.set(ecs.getComponentType<cubz::graphics::PointLight>());
        signature.set(ecs.getComponentType<cubz::graphics::Transform>());
        ecs.setSystemSignature<cubz::core::LightRenderSystem>(signature);

        // Create skybox
        auto skybox = ecs.createEntity();
        ecs.addComponent<cubz::graphics::SkyboxRenderer>(skybox, cubz::graphics::SkyboxRenderer {
            resourceManager.getCubeMap("skybox"),
            resourceManager.getShader("skybox")
        });

        // Create player
        auto player = engine.instantiate<cubz::core::Player>();

        cubz::game::World world(&engine);

        context.setClearColor({0, 0, 0});
        context.setMouseEnabled(false);

        player->setPosition(glm::vec3 { 40, 30, 30 });
        player->lookAt({ 0, 0, 0 });

        // Test light
        // TODO: add torches
        /*auto testLight = ecs.createEntity();
        ecs.addComponent<cubz::graphics::PointLight>(testLight, cubz::graphics::PointLight {
            { 0, 0, 0 },
            1.0f,//1.0f, 2.0f
            0.7f,//0.09f, 0.8f
            1.8f,//0.032f, 2.0f
            glm::vec3(0.1f),
            { 5.0f, 1.0f, 1.0f },
            { 5.0f, 1.0f, 1.0f },
            true
        });
        ecs.updateEntity(testLight);*/

        int i = 0;
        float deltaSum = 0;
        int fpsFrequency = 250;


        for (auto xPos = 0; xPos < cubz::game::CHUNK_SIZE; ++xPos) {
            for (auto yPos = 0; yPos < cubz::game::CHUNK_SIZE; ++yPos) {
                for (auto zPos = 0; zPos < cubz::game::CHUNK_SIZE; ++zPos) {
                    if (yPos + 1 == cubz::game::CHUNK_SIZE) {
                        world.setBlock(cubz::game::BlockType::grass, xPos, yPos, zPos);
                    } else {
                        world.setBlock(cubz::game::BlockType::dirt, xPos, yPos, zPos);
                    }
                }
            }
        }

        world.setBlock(cubz::game::BlockType::torch, 0, 16, 0);

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
            auto [deltaX, deltaY] = context.getMouseMovement();
            auto [forward, side] = context.getPlayerMovement();
            player->updateView(deltaX, deltaY, deltaTime);
            player->updatePosition(forward, side, deltaTime);

            auto playerTransform = player->getComponent<cubz::graphics::Transform>();

            camera.setTransform(playerTransform);

            lightRenderSystem->update(playerTransform.position, true);
            chunkUpdateSystem->updateChunks();
            torchRenderSystem->update();
            meshRenderSystem->update(deltaTime);
            meshRenderSystem->render(camera);
            skyboxRenderSystem->render(camera, playerTransform.position);
            torchRenderSystem->render(camera);
            context.render();
        }
    } catch (std::exception& e) {
        cubz::utility::Log::error(e);
        return 1;
    }

    return 0;
}