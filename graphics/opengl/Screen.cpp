#include "Screen.h"

namespace graphics::opengl {
    Screen::Screen(int width, int height, const std::string &title)
        : m_context(width, height, title) {}

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
}