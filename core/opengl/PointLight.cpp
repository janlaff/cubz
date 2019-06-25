#include "PointLight.h"

namespace core::opengl {
    void PointLight::bind(core::opengl::Shader &shader, int idx) {
        index = "pointLights[" + std::to_string(idx) + "].";
        shader.setVec3(index + "position", position);
        shader.setFloat(index + "constant", constant);
        shader.setFloat(index + "linear", linear);
        shader.setFloat(index + "quadratic", quadratic);
        shader.setVec3(index + "ambient", ambient);
        shader.setVec3(index + "diffuse", diffuse);
        shader.setVec3(index + "specular", specular);
        shader.setInt(index + "isActive", true);
    }

    void PointLight::unbind(core::opengl::Shader &shader) {
        shader.setInt(index + "isActive", false);
    }
}