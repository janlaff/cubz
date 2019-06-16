#include "VertexArray.h"

namespace graphics::opengl {
    VertexArray::VertexArray() {
        glGenVertexArrays(1, &m_id);
    }

    void VertexArray::bind() {
        glBindVertexArray(m_id);
    }

    void VertexArray::unbind() {
        glBindVertexArray(0);
    }
}