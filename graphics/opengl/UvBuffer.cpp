#include "UvBuffer.h"

namespace graphics::opengl {
    UvBuffer::UvBuffer() {
        glGenBuffers(1, &m_id);
    }

    void UvBuffer::update(const std::vector<glm::vec2> &data) {
        glBufferData(GL_ARRAY_BUFFER, data.size() * 2 * sizeof(GLfloat), data.data(), GL_STATIC_DRAW);
    }

    void UvBuffer::bind() {
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
    }

    void UvBuffer::unbind() {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void UvBuffer::draw() {
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
    }
}