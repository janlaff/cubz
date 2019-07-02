#include "Context.h"
#include "Log.h"

using namespace std::string_literals;

namespace cubz::graphics::opengl {
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
        m_window = glfwCreateWindow(m_windowWidth, m_windowHeight, m_windowTitle.c_str(), nullptr, nullptr);

        if (!m_window) {
            throw std::runtime_error("Failed to open window");
        }

        glfwMakeContextCurrent(m_window);
        glfwSwapInterval(0);

        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);


        glewExperimental = GL_TRUE;
        if (glewInit() != GLEW_OK) {
            throw std::runtime_error("Failed to initialize GLEW");
        }

        glfwSetInputMode(m_window, GLFW_STICKY_KEYS, GL_TRUE);

        // Used to hide vertices when inside of an object
        glEnable(GL_CULL_FACE);
        // Render triangles clockwise
        glFrontFace(GL_CW);
        // Use gamma correction
        glEnable(GL_FRAMEBUFFER_SRGB);
    }

    Context::~Context() {
        glfwTerminate();
    }

    void Context::clear() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Context::render() {
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    bool Context::windowClosed() const {
        return glfwWindowShouldClose(m_window);
    }

    void Context::setClearColor(const glm::vec3 &color) {
        glClearColor(color.r, color.g, color.b, 1.0f);
    }

    void Context::setMouseEnabled(bool enabled) {
        glfwSetInputMode(m_window, GLFW_CURSOR, enabled ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_HIDDEN);
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

    std::pair<float, float> Context::getMouseMovement() const {
        double xPos;
        double yPos;
        // fetch movement
        glfwGetCursorPos(m_window, &xPos, &yPos);

        float deltaX = xPos - getWindowWidth() / 2.0;
        float deltaY = yPos - getWindowHeight() / 2.0;

        // Reset mouse
        glfwSetCursorPos(m_window, getWindowWidth() / 2.0, getWindowHeight() / 2.0);

        return { deltaX, deltaY };
    }

    std::pair<float, float> Context::getPlayerMovement() const {
        auto forward = 0.0f;
        auto side = 0.0;

        if (glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS) {
            forward = 1.0f;
        }
        else if (glfwGetKey(m_window, GLFW_KEY_S) == GLFW_PRESS) {
            forward = -1.0f;
        }

        if (glfwGetKey(m_window, GLFW_KEY_D) == GLFW_PRESS) {
            side = 1.0f;
        }
        else if (glfwGetKey(m_window, GLFW_KEY_A) == GLFW_PRESS) {
            side = -1.0f;
        }

        return { forward, side };
    }
}