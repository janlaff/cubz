#include "OpenGLContext.h"
#include "Log.h"

using namespace std::string_literals;

namespace graphics {
    OpenGLContext::OpenGLContext(int windowWidth, int windowHeight, const std::string &windowTitle)
            : m_windowWidth(windowWidth)
            , m_windowHeight(windowHeight)
            , m_windowTitle(windowTitle)
            , m_window(nullptr) {
        glfwSetErrorCallback([](int error, const char* description) {
            utility::Log::error("[GLFW] " + std::string(description));
        });

        if (!glfwInit()) {
            throw std::runtime_error("Failed to initialize GLFW");
        }

        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_window = glfwCreateWindow(m_windowWidth, m_windowHeight, m_windowTitle.c_str(), nullptr, nullptr);

        if (!m_window) {
            throw std::runtime_error("Failed to open window");
        }

        glfwMakeContextCurrent(m_window);

        glewExperimental = GL_TRUE;
        if (glewInit() != GLEW_OK) {
            throw std::runtime_error("Failed to initialize GLEW");
        }
    }

    OpenGLContext::~OpenGLContext() {
        glfwTerminate();
    }

    int OpenGLContext::getWindowWidth() const {
        return m_windowWidth;
    }

    int OpenGLContext::getWindowHeight() const {
        return m_windowHeight;
    }

    const std::string& OpenGLContext::getWindowTitle() const {
        return m_windowTitle;
    }

    GLFWwindow* OpenGLContext::getWindow() const {
        return m_window;
    }
}