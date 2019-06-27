#include "DirectionalLight.h"

namespace cubz::graphics::opengl {
    void DirectionalLight::bind(cubz::graphics::opengl::Shader &shader) {
        shader.setVec3("dirLight.direction", direction);
        shader.setVec3("dirLight.ambient", ambient);
        shader.setVec3("dirLight.diffuse", diffuse);
        shader.setVec3("dirLight.specular", specular);
        shader.setInt("dirLight.isActive", true);
    }

    void DirectionalLight::unbind(cubz::graphics::opengl::Shader &shader) {
        shader.setInt("dirLight.isActive", false);
    }
}