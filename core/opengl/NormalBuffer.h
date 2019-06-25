#pragma once

#include "VertexBuffer.h"

namespace core::opengl {
    class NormalBuffer : public VertexBuffer {
    public:
        using VertexBuffer::VertexBuffer;

        void setAttribPointer() override;
        void calculateNormals(const std::vector<glm::vec3> triangles);
    };
}