#pragma once

#include "opengl/Context.h"
#include "Camera.h"

namespace core::opengl {
    class Screen {
    public:
        Screen(int width, int height, const std::string& title);

        bool shouldQuit() const;
        void render();
        void clear();
        void processInput();
        const Context& getContext() const;
        Camera& getCamera();
    private:
        Context m_context;
        Camera m_camera;
        float m_deltaTime;
        float m_lastFrame;
    };
}