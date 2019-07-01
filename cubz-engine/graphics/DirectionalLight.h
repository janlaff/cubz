#pragma once

#include "opengl/Shader.h"

namespace cubz::graphics {
    struct DirectionalLight {
        glm::vec3 direction;
        glm::vec3 ambient;
        glm::vec3 diffuse;
        glm::vec3 specular;

        void bind(opengl::Shader &shader);
        void unbind(opengl::Shader& shader);
    };
}