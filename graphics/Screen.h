#pragma once

#include "opengl/Context.h"
#include "opengl/VertexArray.h"

#include "Camera.h"

namespace graphics::opengl {
    class Screen {
    public:
        Screen(int width, int height, const std::string& title);

        bool shouldQuit() const;
        void render();
        void clear();
        const Context& getContext() const;
        const Camera& getCamera() const;
    private:
        Context m_context;
        Camera m_camera;
    };
}