#pragma once

#include "Camera.h"
#include "MeshRenderer.h"

namespace graphics {
    class Model {
    public:
        Model(const std::string& shader);

        void render(const Camera& camera);

    private:
        opengl::Shader m_shader;
        Mesh m_mesh;
        MeshRenderer m_meshRenderer;
        glm::vec3 m_position;
    };
}