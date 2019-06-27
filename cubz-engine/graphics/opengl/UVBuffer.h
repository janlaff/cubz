#pragma once

#include <vector>

#include <glm/vec2.hpp>

#include "AbstractBuffer.h"

namespace cubz::graphics::opengl {
    class UVBuffer : public AbstractBuffer {
    public:
        UVBuffer();

        void setAttribPointer();
        void update(const std::vector<glm::vec2>& data);
    };
}