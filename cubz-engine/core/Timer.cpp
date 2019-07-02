#include "Timer.h"

#include <GLFW/glfw3.h>

namespace cubz::core {
    Timer::Timer() : m_lastFrame(0), m_deltaTime(0) {}

    float Timer::getDeltaTime() {
        return m_deltaTime;
    }

    void Timer::update() {
        auto currentFrame = glfwGetTime();
        m_deltaTime = currentFrame - m_lastFrame;
        m_lastFrame = currentFrame;
    }
}