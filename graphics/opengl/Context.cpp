#include "Context.h"
#include "Log.h"

using namespace std::string_literals;

namespace graphics::opengl {
    Context::Context(int windowWidth, int windowHeight, const std::string &windowTitle)
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
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        m_window = glfwCreateWindow(m_windowWidth, m_windowHeight, m_windowTitle.c_str(), nullptr, nullptr);

        if (!m_window) {
            throw std::runtime_error("Failed to open window");
        }

        glfwMakeContextCurrent(m_window);

        glewExperimental = GL_TRUE;
        if (glewInit() != GLEW_OK) {
            throw std::runtime_error("Failed to initialize GLEW");
        }

        glfwSetInputMode(m_window, GLFW_STICKY_KEYS, GL_TRUE);
        glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    }

    Context::~Context() {
        glfwTerminate();
    }

    int Context::getWindowWidth() const {
        return m_windowWidth;
    }

    int Context::getWindowHeight() const {
        return m_windowHeight;
    }

    const std::string& Context::getWindowTitle() const {
        return m_windowTitle;
    }

    GLFWwindow* Context::getWindow() const {
        return m_window;
    }
}