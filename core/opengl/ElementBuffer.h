#pragma once

#include <vector>

#include "AbstractBuffer.h"

namespace core::opengl {
    class ElementBuffer : public AbstractBuffer {
    public:
        ElementBuffer();

        void setAttribPointer();
        void update(const std::vector<GLuint>& data);
        void draw();

    private:
        GLuint m_size;
    };
}