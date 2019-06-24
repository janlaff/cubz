#pragma once

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace core::opengl {
    class Context {
    public:
        Context(int windowWidth, int windowHeight, const std::string& windowTitle);
        ~Context();

        int getWindowWidth() const;
        int getWindowHeight() const;
        const std::string& getWindowTitle() const;
        GLFWwindow* getWindow() const;

    private:
        int m_windowWidth;
        int m_windowHeight;
        std::string m_windowTitle;
        GLFWwindow* m_window;
    };
}