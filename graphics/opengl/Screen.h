#pragma once

#include "Context.h"
#include "VertexArray.h"

namespace graphics::opengl {
    class Screen {
    public:
        Screen(int width, int height, const std::string& title);

        bool shouldQuit() const;
        void render();
        void clear();
    private:
        Context m_context;
    };
}