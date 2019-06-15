#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "../utility/Log.h"
#include "../utility/ConsoleLogger.h"

using namespace std::string_literals;

int main() {
    utility::Log::addLogger(std::make_shared<utility::ConsoleLogger>());

    // FIXME: needed for wsl build
    setenv("DISPLAY", ":0", true);

    auto glfwErrorCallback = [](int error, const char* description) {
        utility::Log::error("[GLFW] "s + std::string(description));
    };

    glfwSetErrorCallback(glfwErrorCallback);

    if (!glfwInit()) {
        utility::Log::error("Failed to initialize GLFW");
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    auto window = glfwCreateWindow(800, 600, "Cubz - Experimental Version", nullptr, nullptr);

    if (window == nullptr) {
        utility::Log::error("Failed to open window");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) {
        utility::Log::error("Failed to initialize GLEW");
        glfwTerminate();
        return -1;
    }

    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}