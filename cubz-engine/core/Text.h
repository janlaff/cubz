#pragma once

#include "GameObject.h"

namespace cubz::core {
    class Text : public GameObject {
    public:
        Text(Engine* engine);

        void setColor(const glm::vec3& color);
        void setText(const std::string& text);
        void setPosition(const glm::vec2& position);
    };
}