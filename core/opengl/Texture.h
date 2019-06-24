#pragma once

#include <string>
#include <GL/glew.h>

namespace core::opengl {
    class Texture {
    public:
        Texture(GLuint id, int width, int height);
        Texture(const std::string& name);

        int getWidth() const;
        int getHeight() const;

        void bind() const;
        void unbind() const;

    private:
        GLuint m_id;
        int m_width;
        int m_height;
    };
}