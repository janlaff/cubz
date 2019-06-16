#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "utility/Log.h"
#include "utility/ConsoleLogger.h"
#include "graphics/Screen.h"
#include "graphics/Model.h"

using namespace std::string_literals;

int main() {
    utility::Log::addLogger(std::make_shared<utility::ConsoleLogger>());

    try {
        auto screen = graphics::opengl::Screen(800, 600, "Cubz - Experimental Version");
        auto model = graphics::Model("triangle", "stone.bmp");

        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

        while (!screen.shouldQuit()) {
            screen.clear();
            model.render(screen.getCamera());
            screen.render();
        }
    } catch (std::exception &e) {
        utility::Log::error(e);
    }

    return 0;
}