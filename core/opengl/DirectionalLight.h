#pragma once

#include "Shader.h"

namespace core::opengl {
    struct DirectionalLight {
        glm::vec3 direction;
        glm::vec3 ambient;
        glm::vec3 diffuse;
        glm::vec3 specular;

        void bind(Shader &shader);
        void unbind(Shader& shader);
    };
}