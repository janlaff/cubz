#pragma once

#include "opengl/Shader.h"

namespace cubz::graphics {
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

        void bind(opengl::Shader &shader, int idx);
        void unbind(opengl::Shader& shader);
    };
}