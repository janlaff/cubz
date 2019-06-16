#pragma once

#include <vector>

#include <GL/glew.h>
#include <glm/vec2.hpp>

namespace graphics::opengl {
    class UvBuffer {
    public:
        UvBuffer();

        void update(const std::vector<glm::vec2>& data);
        void bind();
        void unbind();
        void draw();

    private:
        GLuint m_id;
    };
}