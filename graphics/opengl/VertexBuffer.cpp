#include "VertexBuffer.h"

namespace graphics::opengl {
    VertexBuffer::VertexBuffer() {
        glGenBuffers(1, &m_id);
    }

    void VertexBuffer::update(const std::vector<GLfloat> &data) {
        m_triangles = data.size() / 3;
        glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLfloat), data.data(), GL_STATIC_DRAW);
    }

    void VertexBuffer::bind() {
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
    }

    void VertexBuffer::unbind() {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void VertexBuffer::draw() {
        glVertexAttribPointer(0, m_triangles, GL_FLOAT, GL_FALSE, 0, nullptr);
        glDrawArrays(GL_TRIANGLES, 0, m_triangles);
    }
}