#include "Material.h"

namespace cubz::graphics::opengl {
    void Material::bind(cubz::graphics::opengl::Shader &shader) {
        shader.setInt("material.texture", 0);
        glActiveTexture(GL_TEXTURE0);
        texture.bind();
        shader.setVec3("material.specular", specular);
        shader.setFloat("material.shininess", shininess);
        shader.setInt("material.isActive", true);
    }

    void Material::unbind(Shader& shader) {
        shader.setInt("material.isActive", false);
    }
}