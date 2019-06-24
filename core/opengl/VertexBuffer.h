#pragma once

#include <vector>

#include <glm/vec3.hpp>

#include "AbstractBuffer.h"

namespace core::opengl {
    class VertexBuffer : public AbstractBuffer {
    public:
        VertexBuffer();

        void setAttribPointer();
        void update(const std::vector<glm::vec3>& data, bool dynamic);
        void partialUpdate(const std::vector<glm::vec3>& data);
        void draw();

    private:
        size_t m_triangles;
    };
}