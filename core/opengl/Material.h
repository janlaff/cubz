#pragma once

#include "Shader.h"
#include "Texture.h"

namespace core::opengl {
    struct Material {
        Texture texture;
        glm::vec3 specular;
        GLfloat shininess;

        void bind(Shader &shader);
        void unbind(Shader& shader);
    };
}