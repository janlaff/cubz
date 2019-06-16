#include "Screen.h"
#include "Log.h"

namespace graphics::opengl {
    Screen::Screen(int width, int height, const std::string &title)
        : m_context(width, height, title)
        , m_camera(width, height)
        , m_deltaTime(0.0f)
        , m_lastFrame(0.0f) {}

    bool Screen::shouldQuit() const {
        return glfwWindowShouldClose(m_context.getWindow());
    }

    void Screen::render() {
        glfwSwapBuffers(m_context.getWindow());
        glfwPollEvents();
    }

    void Screen::clear() {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Screen::processInput() {
        float currentFrame = glfwGetTime();
        m_deltaTime = currentFrame - m_lastFrame;
        m_lastFrame = currentFrame;

        double xPos;
        double yPos;
        glfwGetCursorPos(m_context.getWindow(), &xPos, &yPos);
        m_camera.changeDirection(m_context.getWindowWidth() / 2.0 - xPos, m_context.getWindowHeight() / 2.0 - yPos, m_deltaTime);
        glfwSetCursorPos(m_context.getWindow(), m_context.getWindowWidth() / 2.0, m_context.getWindowHeight() / 2.0);

        if (glfwGetKey(m_context.getWindow(), GLFW_KEY_W) == GLFW_PRESS) {
            m_camera.moveForward(m_deltaTime);
        } else if (glfwGetKey(m_context.getWindow(), GLFW_KEY_S) == GLFW_PRESS) {
            m_camera.moveBackward(m_deltaTime);
        }

        if (glfwGetKey(m_context.getWindow(), GLFW_KEY_A) == GLFW_PRESS) {
            m_camera.moveLeft(m_deltaTime);
        } else if (glfwGetKey(m_context.getWindow(), GLFW_KEY_D) == GLFW_PRESS) {
            m_camera.moveRight(m_deltaTime);
        }
    }

    const Context& Screen::getContext() const {
        return m_context;
    }

    const Camera& Screen::getCamera() const {
        return m_camera;
    }
}