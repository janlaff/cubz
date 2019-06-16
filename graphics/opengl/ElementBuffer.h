#pragma once

#include <vector>
#include <GL/glew.h>

namespace graphics::opengl {
    class ElementBuffer {
    public:
        ElementBuffer();

        void update(const std::vector<GLuint>& data);
        void bind();
        void unbind();
        void draw();

    private:
        GLuint m_id;
        GLuint m_size;
    };
}