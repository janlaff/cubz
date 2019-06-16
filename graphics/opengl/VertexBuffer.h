#pragma once

#include <vector>
#include <GL/glew.h>

namespace graphics::opengl {
    class VertexBuffer {
    public:
        VertexBuffer();

        void update(const std::vector<GLfloat>& data);
        void bind();
        void unbind();
        void draw();

    private:
        GLuint m_id;
        size_t m_triangles;
    };
}