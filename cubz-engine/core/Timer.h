#pragma once

namespace cubz::core {
    class Timer {
    public:
        Timer();

        float getDeltaTime();
        void update();

    private:
        float m_deltaTime;
        float m_lastFrame;
    };
}