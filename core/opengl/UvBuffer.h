#pragma once

#include <vector>

#include <glm/vec2.hpp>

#include "AbstractBuffer.h"

namespace core::opengl {
    class UvBuffer : public AbstractBuffer {
    public:
        UvBuffer();

        void setAttribPointer();
        void update(const std::vector<glm::vec2>& data);
    };
}