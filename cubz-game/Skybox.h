#pragma once

#include "opengl/CubeMap.h"
#include "opengl/Shader.h"
#include "opengl/VertexBuffer.h"
#include "opengl/VertexArray.h"
#include "Camera.h"

namespace cubz::game {
    class Skybox {
    public:
        Skybox();

        void render(const graphics::Camera& camera, const glm::vec3& position, float ambient);

    private:
        graphics::opengl::CubeMap m_cubeMap;
        graphics::opengl::Shader m_shader;
        graphics::opengl::VertexArray m_vertexArray;
        graphics::opengl::VertexBuffer m_vertexBuffer;
    };
}