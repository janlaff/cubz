#include "AbstractBuffer.h"

namespace graphics::opengl {
    AbstractBuffer::AbstractBuffer(GLint type) : m_type(type) {
        glGenBuffers(1, &m_id);
    }

    AbstractBuffer::~AbstractBuffer() {
        glDeleteBuffers(1, &m_id);
    }

    void AbstractBuffer::bind() {
        glBindBuffer(m_type, m_id);
    }

    void AbstractBuffer::unbind() {
        glBindBuffer(m_type, 0);
    }
}