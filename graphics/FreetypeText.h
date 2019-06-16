#pragma once

#include <memory>

#include "opengl/VertexArray.h"
#include "opengl/VertexBuffer.h"
#include "opengl/Shader.h"
#include "FreetypeFont.h"
#include "Camera.h"

#include <glm/mat4x4.hpp>

namespace graphics {
    class FreetypeText {
    public:
        FreetypeText(const FreetypeFont& font, opengl::Shader shader);

        void setPosition(float x, float y);
        void setColor(glm::vec3 color);
        void setText(const std::string& text);
        void render(const Camera& camera);

    private:
        const FreetypeFont& m_font;
        opengl::VertexArray m_vertexArray;
        opengl::VertexBuffer m_vertexBuffer;
        opengl::Shader m_shader;
        float m_x;
        float m_y;
        glm::vec3 m_color;
    };
}