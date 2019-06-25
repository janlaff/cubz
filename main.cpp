#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "utility/Log.h"
#include "utility/ConsoleLogger.h"
#include "core/Screen.h"
#include "core/Chunk.h"
#include "core/ui/FreetypeContext.h"
#include "core/ui/FreetypeText.h"
#include "core/ResourceManager.h"
#include "core/ui/DebugView.h"
#include "core/GrassBlock.h"
#include "core/World.h"

using namespace std::string_literals;

int main() {
    utility::Log::addLogger(std::make_shared<utility::ConsoleLogger>());

    try {
        auto screen = core::opengl::Screen(800, 600, "Cubz - Experimental Version");
        screen.getCamera().setPosition({ 0.0f, 1.0f, -2.0f });

        auto world = core::World();
        world.setBlock(std::make_shared<core::GrassBlock>(), 0, 3, 0);

        auto fontCtx = core::ui::FreetypeContext();
        auto font = fontCtx.generateFont("OpenSans-Regular.ttf", 24);

        auto debugView = core::ui::DebugView(font);

        auto chunkShader = core::ResourceManager::getInstance().getShader("chunk");

        // Light properties
        auto diffuse = glm::vec3(1.0f);
        auto ambient = glm::vec3(1.0f);
        auto specular = glm::vec3(1.0f);
        auto color = glm::vec3(1.0f, 1.0f, 1.0f);

        chunkShader.bind();
        // Light
        chunkShader.setVec3("light.position",  { 0, 3, 0 });
        chunkShader.setVec3("light.ambient", ambient * color);
        chunkShader.setVec3("light.diffuse", diffuse * color);
        chunkShader.setVec3("light.specular", specular * color);
        // Material
        chunkShader.setVec3("material.specular", { 1.0f, 1.0f, 1.0f });
        chunkShader.setFloat("material.shininess", 32);
        chunkShader.unbind();

        while (!screen.shouldQuit()) {
            chunkShader.bind();
            chunkShader.setVec3("playerPosition", screen.getCamera().getPosition());
            chunkShader.unbind();

            screen.clear();
            world.update();
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