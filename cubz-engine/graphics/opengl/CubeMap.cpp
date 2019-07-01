#include "CubeMap.h"

#include <stdexcept>

namespace cubz::graphics::opengl {
    CubeMap::CubeMap(const std::string &name) : Texture::Texture(0, 0, GL_TEXTURE_CUBE_MAP) {
        load(name);
    }

    void CubeMap::load(const std::string& name) {
        bind();

        std::string files[] = {
            "right.jpg",
            "left.jpg",
            "top.jpg",
            "bottom.jpg",
            "front.jpg",
            "back.jpg",
        };

        for (GLuint i = 0; i < 6; ++i) {
            auto filename = name + files[i];
            auto image = loadImage(filename);

            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.data);
            glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
        }

        unbind();
    }
}