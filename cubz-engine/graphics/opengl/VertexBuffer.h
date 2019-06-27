#pragma once

#include <vector>

#include <glm/vec3.hpp>

#include "AbstractBuffer.h"

namespace cubz::graphics::opengl {
    class VertexBuffer : public AbstractBuffer {
    public:
        VertexBuffer();

        virtual void setAttribPointer();
        void update(const std::vector<glm::vec3>& data, bool dynamic);
        void partialUpdate(const std::vector<glm::vec3>& data);
        void draw();

    protected:
        size_t m_vertexCount;
    };
}