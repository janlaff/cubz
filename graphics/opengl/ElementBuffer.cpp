#include "ElementBuffer.h"

namespace graphics::opengl {
    ElementBuffer::ElementBuffer() {
        glGenBuffers(1, &m_id);
    }

    void ElementBuffer::update(const std::vector<GLuint> &data) {
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(GLint), data.data(), GL_STATIC_DRAW);
        m_size = data.size();
    }

    void ElementBuffer::bind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
    }

    void ElementBuffer::unbind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    void ElementBuffer::draw() {
        glDrawElements(GL_TRIANGLES, m_size, GL_UNSIGNED_INT, nullptr);
    }
}