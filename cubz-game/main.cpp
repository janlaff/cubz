#include <core/Engine.h>
#include <utility/Log.h>
#include <glm/gtc/matrix_transform.hpp>
#include <core/Player.h>
#include <core/Text.h>
#include <core/DefaultSystems.h>
#include <graphics/BasicComponents.h>
#include <utility/Helpers.h>
#include <graphics/Mesh.h>

#include <core/Skybox.h>

#include "ChunkUpdateSystem.h"
#include "World.h"
#include "ChunkEntity.h"

int main(int argc, char **argv) {
    try {
        auto engine = cubz::core::Engine(1920, 1080, "Cubz Game - Experimental Version", "./assets");

        auto& context = engine.getContext();
        auto& ecs = engine.getECS();
        auto& camera = engine.getCamera();
        auto& resourceManager = engine.getResourceManager();
        auto defaultSystems = cubz::core::DefaultSystems(&engine);

        auto sun = cubz::graphics::DirectionalLight {
                { 1.0f, -1.0f, 1.0f },
                glm::vec3(0.2f),
                glm::vec3(1.0f),
                glm::vec3(1.0f)
        };

        auto lightRenderSystem = defaultSystems.createLightRenderSystem(sun);
        auto meshRenderSystem = defaultSystems.createMeshRenderSystem();
        auto skyboxRenderSystem = defaultSystems.createSkyboxRenderSystem();
        auto textRenderSystem = defaultSystems.createTextRenderSystem();

        // Create custom components
        ecs.registerComponent<cubz::game::ChunkData>();

        // Register chunk update system
        auto chunkUpdateSystem = ecs.registerSystem<cubz::game::ChunkUpdateSystem>();
        auto signature = cubz::ecs::Signature();
        signature.set(ecs.getComponentType<cubz::game::ChunkData>());
        signature.set(ecs.getComponentType<cubz::graphics::Mesh>());
        signature.set(ecs.getComponentType<cubz::graphics::Transform>());
        ecs.setSystemSignature<cubz::game::ChunkUpdateSystem>(signature);

        // Create skybox
        auto skybox = engine.instantiate<cubz::core::Skybox>();
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
        int textUpdateFrequency = 250;


        int miniWorldSize = 32;
        for (auto xPos = -miniWorldSize; xPos < miniWorldSize; ++xPos) {
            for (auto yPos = 0; yPos < 16; ++yPos) {
                for (auto zPos = -miniWorldSize; zPos < miniWorldSize; ++zPos) {
                    if (yPos + 1 == 16) {
                        world.setBlock(cubz::game::BlockType::grass, xPos, yPos, zPos);
                    } else {
                        world.setBlock(cubz::game::BlockType::dirt, xPos, yPos, zPos);
                    }
                }
            }
        }

        world.setBlock(cubz::game::BlockType::torch, 0, 16, 0);
        world.setBlock(cubz::game::BlockType::dirt, 2, 16, 0);
        world.setBlock(cubz::game::BlockType::grass, 4, 16, 0);
        world.setBlock(cubz::game::BlockType::stone, 6, 16, 0);

        auto charMap = resourceManager.generateCharMap("OpenSans-Regular.ttf", 24);
        auto fpsText = engine.instantiate<cubz::core::Text>();
        auto positionText = engine.instantiate<cubz::core::Text>();

        positionText->setPosition({ 10, 40 });

        int frames = 0;

        while (!context.windowClosed()) {
            float deltaTime = context.getDeltaTime();

            deltaSum += deltaTime;
            ++frames;

            auto [deltaX, deltaY] = context.getMouseMovement();
            auto [forward, side] = context.getPlayerMovement();
            player->updateView(deltaX, deltaY, deltaTime);
            player->updatePosition(forward, side, deltaTime);

            auto playerTransform = player->getComponent<cubz::graphics::Transform>();

            camera.setTransform(playerTransform);

            if (deltaSum >= 0.5f) {
                float averageDeltaTime = deltaSum / frames;
                int fps = 1.0f / averageDeltaTime;

                fpsText->setText("Fps: " + std::to_string(fps));
                positionText->setText("Position: " + cubz::utility::vectorToString(playerTransform.position));

                i = 0;
                deltaSum = 0;
                frames = 0;
            }

            context.clear();
            lightRenderSystem->update(playerTransform.position, true);
            chunkUpdateSystem->updateChunks();
            meshRenderSystem->update(deltaTime);
            textRenderSystem->update();

            meshRenderSystem->render(camera);
            skyboxRenderSystem->render(camera, playerTransform.position, 1.0f);
            textRenderSystem->render(camera, charMap);
            context.render();
        }
    } catch (std::exception& e) {
        cubz::utility::Log::error(e);
        return 1;
    }

    return 0;
}