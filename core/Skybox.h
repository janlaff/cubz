#pragma once

#include "opengl/CubeMap.h"
#include "opengl/Shader.h"
#include "opengl/VertexBuffer.h"
#include "opengl/VertexArray.h"
#include "Camera.h"

namespace core {
    class Skybox {
    public:
        Skybox();

        void render(const Camera& camera, const glm::vec3& position, float ambient);

    private:
        opengl::CubeMap m_cubeMap;
        opengl::Shader m_shader;
        opengl::VertexArray m_vertexArray;
        opengl::VertexBuffer m_vertexBuffer;
    };
}