#pragma once

#include "Camera.h"
#include "MeshRenderer.h"
#include "opengl/Texture.h"

namespace graphics {
    class Model {
    public:
        Model(const std::string& shader, const std::string& texture);

        void render(const Camera& camera);

    private:
        opengl::Shader m_shader;
        opengl::Texture m_texture;
        Mesh m_mesh;
        MeshRenderer m_meshRenderer;
        glm::vec3 m_position;
    };
}