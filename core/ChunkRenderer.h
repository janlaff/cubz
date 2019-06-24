#pragma once

#include "opengl/VertexBuffer.h"
#include "opengl/UvBuffer.h"
#include "opengl/VertexArray.h"
#include "opengl/ElementBuffer.h"
#include "opengl/Shader.h"
#include "opengl/Texture.h"
#include "MeshData.h"
#include "Camera.h"

namespace core {
    class ChunkRenderer {
    public:
        ChunkRenderer();

        MeshData& getMeshData();
        void update();
        void render(const Camera& camera, const glm::vec3& position);

    private:
        opengl::VertexBuffer m_vertexBuffer;
        opengl::UvBuffer m_uvBuffer;
        opengl::ElementBuffer m_elementBuffer;
        opengl::VertexArray m_vertexArray;
        opengl::Shader m_shader;
        opengl::Texture m_texture;
        MeshData m_meshData;
    };
}