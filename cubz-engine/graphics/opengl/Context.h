#pragma once

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>

namespace cubz::graphics::opengl {
    class Context {
    public:
        Context(int windowWidth, int windowHeight, const std::string& windowTitle);
        ~Context();

        void clear();
        void render();
        bool windowClosed() const;
        void setClearColor(const glm::vec3& color);
        void setMouseEnabled(bool enabled);
        int getWindowWidth() const;
        int getWindowHeight() const;
        const std::string& getWindowTitle() const;
        GLFWwindow* getWindow() const;
        float getDeltaTime() const;

    private:
        int m_windowWidth;
        int m_windowHeight;
        std::string m_windowTitle;
        GLFWwindow* m_window;
        float m_deltaTime;
        float m_lastFrame;
    };
}