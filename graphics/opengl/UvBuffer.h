#pragma once

#include <vector>

#include <glm/vec2.hpp>

#include "AbstractBuffer.h"

namespace graphics::opengl {
    class UvBuffer : public AbstractBuffer {
    public:
        UvBuffer();

        void update(const std::vector<glm::vec2>& data);
    };
}