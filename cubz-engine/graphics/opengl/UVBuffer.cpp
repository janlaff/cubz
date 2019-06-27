#include "UVBuffer.h"

namespace cubz::graphics::opengl {
    UVBuffer::UVBuffer() : AbstractBuffer(GL_ARRAY_BUFFER) {}

    void UVBuffer::setAttribPointer() {
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
    }

    void UVBuffer::update(const std::vector<glm::vec2> &data) {
        glBufferData(GL_ARRAY_BUFFER, data.size() * 2 * sizeof(GLfloat), data.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
    }
}