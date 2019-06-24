#include "VertexArray.h"

namespace core::opengl {
    VertexArray::VertexArray() {
        glGenVertexArrays(1, &m_id);
    }

    VertexArray::~VertexArray() {
        glDeleteVertexArrays(1, &m_id);
    }

    void VertexArray::enableAttrib(GLint id) {
        glEnableVertexAttribArray(id);
    }

    void VertexArray::bind() {
        glBindVertexArray(m_id);
    }

    void VertexArray::unbind() {
        glBindVertexArray(0);
    }
}