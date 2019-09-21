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
#include <imgui.h>

int main(int argc, char **argv) {
    try {
        auto engine = cubz::core::Engine(1920, 1080, "Cubz Game - Experimental Version", "./assets");

        auto& context = engine.getContext();
        auto& ecs = engine.getECS();
        auto& camera = engine.getCamera();
        auto& resourceManager = engine.getResourceManager();
        auto defaultSystems = cubz::core::DefaultSystems(&engine);
        auto guiContext = cubz::graphics::gui::ImGuiContext(context);

        auto sun = cubz::graphics::DirectionalLight {
                { 1.0f, -1.0f, 1.0f },
                glm::vec3(0.2f),
                glm::vec3(1.0f),
                glm::vec3(1.0f)
        };

        auto lightRenderSystem = defaultSystems.createLightRenderSystem(sun);
        auto meshRenderSystem = defaultSystems.createMeshRenderSystem();
        auto skyboxRenderSystem = defaultSystems.createSkyboxRenderSystem();
        // Create skybox
        auto skybox = engine.instantiate<cubz::core::Skybox>();
        // Create player
        auto player = engine.instantiate<cubz::core::Player>();
        player->setPosition(glm::vec3 { 40, 30, 30 });

        // Context properties
        context.setClearColor({0, 0, 0});

        int frames = 0;
        float deltaSum = 0;
        int fps = 0;
        auto timer = cubz::core::Timer();

        while (!context.windowClosed()) {
            float deltaTime = timer.getDeltaTime();

            deltaSum += deltaTime;
            ++frames;

            if (deltaSum >= 0.25f) {
                float averageDeltaTime = deltaSum / frames;
                fps = 1.0f / averageDeltaTime;
                deltaSum = 0;
                frames = 0;
            }

            guiContext.newframe();
            context.clear();

            auto& playerTransform = player->getComponent<cubz::graphics::Transform>();

            ImGui::Begin("Player");
            ImGui::Text("Position");
            ImGui::InputFloat3("##position", &playerTransform.position[0]);

            ImGui::Text("Rotation");
            for (int y = 0; y < 3; ++y) {
                ImGui::PushID(y);
                ImGui::InputFloat3("##", &playerTransform.rotation[y][0]);
                ImGui::PopID();
            }

            ImGui::Text("Scale");
            ImGui::InputFloat3("##scale", &playerTransform.scale[0]);

            ImGui::End();

            camera.setTransform(playerTransform);

            ImGui::Begin("Program Stats");
            ImGui::Text("FPS: %d", fps);
            ImGui::End();

            lightRenderSystem->update(playerTransform.position, true);
            meshRenderSystem->update(deltaTime);
            meshRenderSystem->render(camera);
            skyboxRenderSystem->render(camera, playerTransform.position, 1.0f);

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