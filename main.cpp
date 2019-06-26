#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <core/opengl/PointLight.h>
#include <core/DirtBlock.h>
#include <core/Skybox.h>
#include "core/opengl/DirectionalLight.h"
#include "core/opengl/Material.h"

#include "utility/Log.h"
#include "utility/ConsoleLogger.h"
#include "core/Screen.h"
#include "core/Chunk.h"
#include "core/ui/FreetypeContext.h"
#include "core/ui/FreetypeText.h"
#include "core/ResourceManager.h"
#include "core/ui/DebugView.h"
#include "core/World.h"

using namespace std::string_literals;

int main() {
    utility::Log::addLogger(std::make_shared<utility::ConsoleLogger>());

    try {
        auto screen = core::opengl::Screen(1280, 800, "Cubz - Experimental Version");
        screen.getCamera().setPosition({ 0.0f, 1.0f, -2.0f });

        auto world = core::World();
        world.setBlock(core::BlockType::torch, 0, 0, 0);
        world.setBlock(core::BlockType::dirt, 2, 0, 1);

        auto font = core::ResourceManager::getInstance().generateFont("Minecraftia_Regular.ttf", 24);
        auto debugView = core::ui::DebugView(font);

        auto chunkShader = core::ResourceManager::getInstance().getShader("chunk");

        auto dirLight = core::opengl::DirectionalLight {
            { 1.0f, -1.0f, 1.0f },
            glm::vec3(0.2f),
            glm::vec3(1.0f),
            glm::vec3(1.0f)
        };

        chunkShader.bind();
        dirLight.bind(chunkShader);
        chunkShader.unbind();

        while (!screen.shouldQuit()) {
            chunkShader.bind();
            chunkShader.setVec3("playerPosition", screen.getCamera().getPosition());
            chunkShader.unbind();

            screen.clear();
            world.update();
            world.setPlayerPosition(screen.getCamera().getPosition());
            world.render(screen.getCamera());

            debugView.render(screen.getCamera());
            screen.render();
            screen.processInput();
        }
    } catch (std::exception &e) {
        utility::Log::error(e);
    }

    return 0;
}