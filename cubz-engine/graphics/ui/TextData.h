#pragma once

#include <string>

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

namespace cubz::graphics::ui {
    struct TextData {
        std::string value;
        glm::vec2 position;
        glm::vec3 color;
    };
}