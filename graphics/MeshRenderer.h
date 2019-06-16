#pragma once

#include "opengl/VertexBuffer.h"
#include "opengl/ElementBuffer.h"
#include "opengl/Shader.h"
#include "Mesh.h"
#include "Camera.h"

namespace graphics {
    class MeshRenderer {
    public:
        MeshRenderer();

        void render(const Mesh& mesh);

    private:
        opengl::VertexBuffer m_vertexBuffer;
        opengl::ElementBuffer m_elementBuffer;
    };
}