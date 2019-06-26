#include "Texture.h"
#include "Log.h"

#include <stdexcept>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

namespace core::opengl {
    const char* Texture::textureDir = "./assets/textures/";

    Texture::Texture(GLuint id, int width, int height)
        : m_id(id)
        , m_width(width)
        , m_height(height)
        , m_type(GL_TEXTURE_2D) {}

    Texture::Texture(const std::string &name) {
        load(name);
    }

    void Texture::load(const std::string &name) {
        auto image = loadImage(std::string(textureDir) + name);

        bind();

        if (image.comp == 3) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_BGR, GL_UNSIGNED_BYTE, image.data);
        } else {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.data);
        }
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glGenerateMipmap(GL_TEXTURE_2D);
        unbind();

        destroyImage(image);
    }

    int Texture::getWidth() const {
        return m_width;
    }

    int Texture::getHeight() const {
        return m_height;
    }

    void Texture::bind() const {
        glBindTexture(m_type, m_id);
    }

    void Texture::unbind() const {
        glBindTexture(m_type, 0);
    }

    Texture::ImageData Texture::loadImage(const std::string &filename) {
        int comp;

        unsigned char* image = stbi_load(filename.c_str(), &m_width, &m_height, &comp, STBI_rgb_alpha);

        if (!image) {
            throw std::runtime_error("Failed to load image: " + filename);
        }

        return { image, comp };
    }

    void Texture::destroyImage(core::opengl::Texture::ImageData data) {
        stbi_image_free(data.data);
    }
}