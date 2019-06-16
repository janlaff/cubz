#pragma once

#include <vector>

#include "AbstractBuffer.h"

namespace graphics::opengl {
    class ElementBuffer : public AbstractBuffer {
    public:
        ElementBuffer();

        void setAttribPointer();
        void update(const std::vector<GLuint>& data);
        void draw();

    private:
        GLuint m_id;
        GLuint m_size;
    };
}