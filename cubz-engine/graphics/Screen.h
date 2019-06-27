#pragma once

#include "opengl/Context.h"
#include "Camera.h"

namespace cubz::graphics::opengl {
    class Screen {
    public:
        Screen(int width, int height, const std::string& title);

        void setClearColor(const glm::vec3& color);
        bool shouldQuit() const;
        void render();
        void clear();
        void processInput();
        Context& getContext();
        Camera& getCamera();
    private:
        Context m_context;
        Camera m_camera;
        float m_yaw;
        float m_pitch;
        bool m_firstMouse;
    };
}