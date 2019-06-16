#include "ElementBuffer.h"

namespace graphics::opengl {
    ElementBuffer::ElementBuffer() : AbstractBuffer(GL_ELEMENT_ARRAY_BUFFER) {}

    void ElementBuffer::update(const std::vector<GLuint> &data) {
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(GLint), data.data(), GL_STATIC_DRAW);
        m_size = data.size();
    }

    void ElementBuffer::draw() {
        glDrawElements(GL_TRIANGLES, m_size, GL_UNSIGNED_INT, nullptr);
    }
}