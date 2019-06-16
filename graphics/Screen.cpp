#include "Screen.h"

namespace graphics::opengl {
    Screen::Screen(int width, int height, const std::string &title)
        : m_context(width, height, title)
        , m_camera(width, height) {}

    bool Screen::shouldQuit() const {
        return glfwWindowShouldClose(m_context.getWindow());
    }

    void Screen::render() {
        glfwSwapBuffers(m_context.getWindow());
        glfwPollEvents();
    }

    void Screen::clear() {
        //glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    const Context& Screen::getContext() const {
        return m_context;
    }

    const Camera& Screen::getCamera() const {
        return m_camera;
    }
}