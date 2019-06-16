#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <Model.h>

#include "Log.h"
#include "ConsoleLogger.h"
#include "Screen.h"
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

        /*auto vertexBuffer = graphics::opengl::VertexBuffer();
        vertexBuffer.bind();
        vertexBuffer.update({
            glm::vec3(-1.0f, -1.0f, 0.0f),
            glm::vec3(1.0f, -1.0f, 0.0f),
            glm::vec3(0.0f, 1.0f, 0.0f)
        });

        auto shader = graphics::opengl::Shader("triangle");
        shader.bind();*/

        auto model = graphics::Model("triangle");

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