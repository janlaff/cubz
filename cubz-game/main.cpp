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
#include <core/Timer.h>
#include <graphics/gui/ImGuiContext.h>
#include <graphics/gui/ImGuiLogger.h>

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
        auto guiContext = cubz::graphics::gui::ImGuiContext(context);
        auto guiLogger = std::make_shared<cubz::graphics::gui::ImGuiLogger>();

        cubz::utility::Log::addLogger(guiLogger);

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
        player->setPosition(glm::vec3 { 40, 30, 30 });
        player->lookAt({ 0, 0, 0 });

        // Create world
        cubz::game::World world(&engine);
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

        // Context properties
        context.setClearColor({0, 0, 0});
        context.setMouseEnabled(false);

        // Create texts
        auto charMap = resourceManager.generateCharMap("OpenSans-Regular.ttf", 24);
        auto fpsText = engine.instantiate<cubz::core::Text>();
        auto positionText = engine.instantiate<cubz::core::Text>();

        positionText->setPosition({ 10, 40 });

        int frames = 0;
        float deltaSum = 0;
        auto timer = cubz::core::Timer();

        while (!context.windowClosed()) {
            float deltaTime = timer.getDeltaTime();

            deltaSum += deltaTime;
            ++frames;

            auto [deltaX, deltaY] = context.getMouseMovement();
            auto [forward, side] = context.getPlayerMovement();
            player->updateView(deltaX, deltaY, deltaTime);
            player->updatePosition(forward, side, deltaTime);

            auto playerTransform = player->getComponent<cubz::graphics::Transform>();

            camera.setTransform(playerTransform);

            if (deltaSum >= 0.25f) {
                float averageDeltaTime = deltaSum / frames;
                int fps = 1.0f / averageDeltaTime;

                fpsText->setText("Fps: " + std::to_string(fps));
                positionText->setText("Position: " + cubz::utility::vectorToString(playerTransform.position));

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

            guiContext.newframe();
            guiLogger->render("Log");
            guiContext.render();
            context.render();

            // Update timer after all the main code has run
            timer.update();
        }
    } catch (std::exception& e) {
        cubz::utility::Log::error(e);
        return 1;
    }

    return 0;
}