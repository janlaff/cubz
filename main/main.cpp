#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Log.h"
#include "ConsoleLogger.h"
#include "opengl/Screen.h"
#include "opengl/Shader.h"
#include "opengl/VertexArray.h"
#include "opengl/VertexBuffer.h"

using namespace std::string_literals;

int main() {
    utility::Log::addLogger(std::make_shared<utility::ConsoleLogger>());

    try {
        auto screen = graphics::opengl::Screen(800, 600, "Cubz - Experimental Version");

        auto vertexArray = graphics::opengl::VertexArray();
        vertexArray.bind();

        auto vertexBuffer = graphics::opengl::VertexBuffer();
        vertexBuffer.bind();
        vertexBuffer.update({
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f, 1.0f, 0.0f
        });

        auto shader = graphics::opengl::Shader("triangle");
        shader.bind();

        while (!screen.shouldQuit()) {
            screen.clear();

            shader.enableVertexAttribArray(0);
            vertexBuffer.bind();
            vertexBuffer.draw();
            shader.disableVertexAttribArray(0);

            screen.render();
        }
    } catch (std::exception &e) {
        utility::Log::error(e);
    }

    return 0;
}