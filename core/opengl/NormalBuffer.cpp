#include "NormalBuffer.h"

namespace core::opengl {
    void NormalBuffer::setAttribPointer() {
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    }
}