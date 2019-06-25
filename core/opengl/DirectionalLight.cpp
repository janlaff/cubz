#include "DirectionalLight.h"

namespace core::opengl {
    void DirectionalLight::bind(core::opengl::Shader &shader) {
        shader.setVec3("dirLight.direction", direction);
        shader.setVec3("dirLight.ambient", ambient);
        shader.setVec3("dirLight.diffuse", diffuse);
        shader.setVec3("dirLight.specular", specular);
        shader.setInt("dirLight.isActive", true);
    }

    void DirectionalLight::unbind(core::opengl::Shader &shader) {
        shader.setInt("dirLight.isActive", false);
    }
}