#pragma once

#include "opengl/UvBuffer.h"
#include "opengl/VertexBuffer.h"
#include "opengl/VertexArray.h"
#include "opengl/ElementBuffer.h"
#include "opengl/UvBuffer.h"
#include "opengl/Texture.h"
#include "opengl/Shader.h"
#include "Camera.h"

namespace core::ui {
    class FreetypeChar {
    public:
        FreetypeChar(opengl::Texture texture, GLuint advance, const glm::ivec2& size, const glm::ivec2& bearing);

        void render(const Camera &camera, const glm::vec3& color, float x, float y);

        GLuint getAdvance() const;
        int getHeight() const;

    private:
        opengl::Shader m_shader;
        opengl::VertexArray m_vertexArray;
        opengl::VertexBuffer m_vertexBuffer;
        opengl::UvBuffer m_uvBuffer;
        opengl::ElementBuffer m_elementBuffer;
        opengl::Texture m_texture;
        GLuint m_advance;
        int m_height;
    };
}