#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Log.h"
#include "ConsoleLogger.h"
#include "OpenGLContext.h"
#include "OpenGLShader.h"

using namespace std::string_literals;

int main() {
    utility::Log::addLogger(std::make_shared<utility::ConsoleLogger>());

    try {
        auto ctx = graphics::OpenGLContext(800, 600, "Cubz - Experimental Version");
        auto window = ctx.getWindow();

        GLuint vertexArrayId;
        glGenVertexArrays(1, &vertexArrayId);
        glBindVertexArray(vertexArrayId);

        std::array<GLfloat, 9> vertexData {
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f, 1.0f, 0.0f
        };

        GLuint vertexBuffer;
        glGenBuffers(1, &vertexBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData.data(), GL_STATIC_DRAW);

        auto shader = graphics::OpenGLShader("triangle");
        shader.bind();

        while (!glfwWindowShouldClose(window)) {
            glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
            glDrawArrays(GL_TRIANGLES, 0, 3);
            glDisableVertexAttribArray(0);

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    } catch (std::exception& e) {
        utility::Log::error(e);
    }

    return 0;
}