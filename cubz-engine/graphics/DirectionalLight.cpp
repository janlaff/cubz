#include "DirectionalLight.h"

namespace cubz::graphics {
    void DirectionalLight::bind(opengl::Shader &shader) {
        shader.setVec3("dirLight.direction", direction);
        shader.setVec3("dirLight.ambient", ambient);
        shader.setVec3("dirLight.diffuse", diffuse);
        shader.setVec3("dirLight.specular", specular);
        shader.setInt("dirLight.isActive", true);
    }

    void DirectionalLight::unbind(opengl::Shader &shader) {
        shader.setInt("dirLight.isActive", false);
    }
}