#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include <stdexcept>

namespace core::opengl {
    static const auto textureDir = "./assets/textures/";

    Texture::Texture(GLuint id, int width, int height)
        : m_id(id)
        , m_width(width)
        , m_height(height) {}

    Texture::Texture(const std::string &name) {
        int comp;

        unsigned char* image = stbi_load((std::string(textureDir) + name).c_str(), &m_width, &m_height, &comp, STBI_rgb_alpha);

        if (!image) {
            throw std::runtime_error("Failed to load image");
        }

        glGenTextures(1, &m_id);
        bind();

        /*if (comp == 3) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_BGR, GL_UNSIGNED_BYTE, image);
        } else {*/
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
        //}
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glGenerateMipmap(GL_TEXTURE_2D);
        unbind();

        stbi_image_free(image);
    }

    int Texture::getWidth() const {
        return m_width;
    }

    int Texture::getHeight() const {
        return m_height;
    }

    void Texture::bind() const {
        glBindTexture(GL_TEXTURE_2D, m_id);
    }

    void Texture::unbind() const {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}