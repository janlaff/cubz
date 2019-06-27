#include "Screen.h"
#include "Log.h"
#include "ResourceManager.h"

namespace cubz::graphics::opengl {
    Screen::Screen(int width, int height, const std::string &title)
        : m_context(width, height, title)
        , m_camera(width, height)
        , m_deltaTime(0.0f)
        , m_lastFrame(0.0f) {

    }

    void Screen::setClearColor(const glm::vec3 &color) {
        glClearColor(color.x, color.y, color.z, 1.0f);
    }

    bool Screen::shouldQuit() const {
        return glfwWindowShouldClose(m_context.getWindow());
    }

    void Screen::render() {
        glfwSwapBuffers(m_context.getWindow());
        glfwPollEvents();
    }

    void Screen::clear() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Screen::processInput() {


        double xPos;
        double yPos;
        glfwGetCursorPos(m_context.getWindow(), &xPos, &yPos);
        m_camera.changeDirection(xPos - m_context.getWindowWidth() / 2.0, m_context.getWindowHeight() / 2.0 - yPos);
        glfwSetCursorPos(m_context.getWindow(), m_context.getWindowWidth() / 2.0, m_context.getWindowHeight() / 2.0);

        m_camera.setDeltaTime(m_deltaTime);

        if (glfwGetKey(m_context.getWindow(), GLFW_KEY_W) == GLFW_PRESS) {
            m_camera.moveForward();
        } else if (glfwGetKey(m_context.getWindow(), GLFW_KEY_S) == GLFW_PRESS) {
            m_camera.moveBackward();
        }

        if (glfwGetKey(m_context.getWindow(), GLFW_KEY_A) == GLFW_PRESS) {
            m_camera.moveLeft();
        } else if (glfwGetKey(m_context.getWindow(), GLFW_KEY_D) == GLFW_PRESS) {
            m_camera.moveRight();
        }
    }

    Context& Screen::getContext() {
        return m_context;
    }

    Camera& Screen::getCamera() {
        return m_camera;
    }
}