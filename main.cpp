#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "utility/Log.h"
#include "utility/ConsoleLogger.h"
#include "graphics/Screen.h"
#include "graphics/Model.h"
#include "graphics/FreetypeContext.h"
#include "graphics/FreetypeText.h"
#include "graphics/ShaderManager.h"
#include "graphics/DebugView.h"

using namespace std::string_literals;

int main() {
    utility::Log::addLogger(std::make_shared<utility::ConsoleLogger>());

    try {
        auto screen = graphics::opengl::Screen(800, 600, "Cubz - Experimental Version");
        auto model = graphics::Model(graphics::ShaderManager::getInstance().getShader("triangle"), "stone.bmp");

        auto fontCtx = graphics::FreetypeContext();
        auto font = fontCtx.generateFont("Minecraftia_Regular.ttf", 24);

        auto debugView = graphics::DebugView(font);

        while (!screen.shouldQuit()) {
            screen.clear();
            model.setPosition(glm::vec3(0, 0, 0));
            model.render(screen.getCamera());
            debugView.render(screen.getCamera());
            screen.render();
            screen.processInput();
        }
    } catch (std::exception &e) {
        utility::Log::error(e);
    }

    return 0;
}