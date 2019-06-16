#pragma once

#include <vector>
#include <GL/glew.h>
#include <glm/vec3.hpp>

namespace graphics::opengl {
    class VertexBuffer {
    public:
        VertexBuffer();

        void update(const std::vector<glm::vec3>& data);
        void bind();
        void unbind();
        void draw();

    private:
        GLuint m_id;
    };
}