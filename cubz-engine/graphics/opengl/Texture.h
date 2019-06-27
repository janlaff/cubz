#pragma once

#include <string>
#include <GL/glew.h>

namespace cubz::graphics::opengl {
    class Texture {
    public:
        struct ImageData {
            unsigned char* data;
            int comp;
        };

        static const char* textureDir;

        Texture() = default;
        Texture(GLuint id, int width, int height);
        Texture(const std::string& name);

        virtual void load(const std::string& name);

        int getWidth() const;
        int getHeight() const;

        void bind() const;
        void unbind() const;

    protected:
        ImageData loadImage(const std::string& filename);
        void destroyImage(ImageData data);

        GLuint m_id;
        GLint m_type;
        int m_width;
        int m_height;
    };
}