#include "VertexBuffer.h"

namespace graphics::opengl {
    VertexBuffer::VertexBuffer() {
        glGenBuffers(1, &m_id);
    }

    void VertexBuffer::update(const std::vector<glm::vec3> &data) {
        glBufferData(GL_ARRAY_BUFFER, data.size() * 3 * sizeof(GLfloat), data.data(), GL_STATIC_DRAW);
    }

    void VertexBuffer::bind() {
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
    }

    void VertexBuffer::unbind() {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void VertexBuffer::draw() {
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    }
}