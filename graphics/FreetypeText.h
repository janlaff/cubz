#pragma once

#include <memory>

#include "opengl/VertexArray.h"
#include "opengl/VertexBuffer.h"
#include "opengl/UvBuffer.h"
#include "opengl/ElementBuffer.h"
#include "opengl/Shader.h"
#include "FreetypeFont.h"
#include "Camera.h"

#include <glm/mat4x4.hpp>

namespace graphics {
    class FreetypeText {
    public:
        FreetypeText(const FreetypeFont& font, opengl::Shader shader);

        float getWidth() const;
        void setPosition(float x, float y);
        void setColor(glm::vec3 color);
        void setText(const std::string& text);
        void setScale(float scale);
        void render(const Camera& camera);

    private:
        const FreetypeFont& m_font;
        opengl::VertexArray m_vertexArray;
        opengl::VertexBuffer m_vertexBuffer;
        opengl::UvBuffer m_uvBuffer;
        opengl::ElementBuffer m_elementBuffer;
        opengl::Shader m_shader;
        std::string m_text;
        float m_x;
        float m_y;
        float m_scale;
        glm::vec3 m_color;
    };
}