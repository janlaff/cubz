#pragma once

#include <GL/glew.h>

namespace graphics::opengl {
    class AbstractBuffer {
    public:
        AbstractBuffer(GLint type);
        ~AbstractBuffer();

        void bind();
        void unbind();

    protected:
        GLuint m_id;
        GLint m_type;
    };
}