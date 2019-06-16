#include "VertexBuffer.h"

namespace graphics::opengl {
    VertexBuffer::VertexBuffer() : AbstractBuffer(GL_ARRAY_BUFFER) {}

    void VertexBuffer::update(const std::vector<glm::vec3> &data, bool dynamic) {
        glBufferData(GL_ARRAY_BUFFER, data.size() * 3 * sizeof(GLfloat), data.data(), dynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
        m_triangles = data.size();
    }

    void VertexBuffer::partialUpdate(const std::vector<glm::vec3> &data) {
        glBufferSubData(GL_ARRAY_BUFFER, 0, data.size() * 3, data.data());
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
        m_triangles = data.size();
    }

    void VertexBuffer::draw() {
        glDrawArrays(GL_TRIANGLES, 0, m_triangles);
    }
}