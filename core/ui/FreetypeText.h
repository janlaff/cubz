#pragma once

#include <memory>

#include "opengl/VertexArray.h"
#include "opengl/VertexBuffer.h"
#include "opengl/UvBuffer.h"
#include "opengl/ElementBuffer.h"
#include "opengl/Shader.h"
#include "FreetypeCharMap.h"
#include "Camera.h"

#include <glm/mat4x4.hpp>

namespace core::ui {
    class FreetypeText {
    public:
        FreetypeText(FreetypeCharMap& m_charMap);

        float getWidth() const;
        void setPosition(const glm::vec2& position);
        void setColor(const glm::vec3& color);
        void setText(const std::string& text);
        void render(const Camera& camera);

    private:
        FreetypeCharMap& m_charMap;
        std::string m_text;
        float m_x;
        float m_y;
        glm::vec3 m_color;
    };
}