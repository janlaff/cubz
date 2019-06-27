#pragma once

#include "Shader.h"

namespace cubz::graphics::opengl {
    struct PointLight {
        glm::vec3 position;
        GLfloat constant;
        GLfloat linear;
        GLfloat quadratic;
        glm::vec3 ambient;
        glm::vec3 diffuse;
        glm::vec3 specular;
        GLboolean isActive = true;
        std::string index = "";

        void bind(Shader &shader, int idx);
        void unbind(Shader& shader);
    };
}