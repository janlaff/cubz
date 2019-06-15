#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Log.h"
#include "ConsoleLogger.h"
#include "OpenGLContext.h"

using namespace std::string_literals;

int main() {
    utility::Log::addLogger(std::make_shared<utility::ConsoleLogger>());

    try {
        auto ctx = graphics::OpenGLContext(800, 600, "Cubz - Experimental Version");
        auto window = ctx.getWindow();

        while (!glfwWindowShouldClose(window)) {
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    } catch (std::exception& e) {
        utility::Log::error(e);
    }

    return 0;
}