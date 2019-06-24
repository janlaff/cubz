#pragma once

#include <GL/glew.h>

namespace core::opengl {
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