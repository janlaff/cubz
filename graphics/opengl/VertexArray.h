#pragma once

#include <GL/glew.h>

namespace graphics::opengl {
    class VertexArray {
    public:
        VertexArray();

        void bind();
        void unbind();

    private:
        GLuint m_id;
    };
}