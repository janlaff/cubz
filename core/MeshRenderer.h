#pragma once

#include "opengl/VertexBuffer.h"
#include "opengl/UvBuffer.h"
#include "opengl/VertexArray.h"
#include "opengl/ElementBuffer.h"
#include "opengl/Shader.h"
#include "Mesh.h"
#include "Camera.h"

namespace core {
    class MeshRenderer {
    public:
        MeshRenderer();

        void update(const Mesh& mesh);
        void render();

    private:
        opengl::VertexBuffer m_vertexBuffer;
        opengl::UvBuffer m_uvBuffer;
        opengl::ElementBuffer m_elementBuffer;
        opengl::VertexArray m_vertexArray;
    };
}