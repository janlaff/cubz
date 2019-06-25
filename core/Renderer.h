#pragma once

#include "opengl/PointLight.h"
#include "opengl/VertexBuffer.h"
#include "opengl/NormalBuffer.h"
#include "opengl/UvBuffer.h"
#include "opengl/VertexArray.h"
#include "opengl/ElementBuffer.h"
#include "opengl/Shader.h"
#include "opengl/Texture.h"
#include "MeshData.h"
#include "WorldPos.h"
#include "Camera.h"

namespace core {
    class Renderer {
    public:
        Renderer();

        MeshData& getMeshData();
        void update();
        void updateLights(const WorldPosMap<opengl::PointLight>& lights);
        virtual void render(const Camera& camera, const glm::vec3& position);

    protected:
        opengl::VertexBuffer m_vertexBuffer;
        opengl::NormalBuffer m_normalBuffer;
        opengl::ElementBuffer m_elementBuffer;
        opengl::UvBuffer m_uvBuffer;
        opengl::VertexArray m_vertexArray;
        opengl::Shader m_shader;
        opengl::Texture m_texture;
        MeshData m_meshData;
    };
}