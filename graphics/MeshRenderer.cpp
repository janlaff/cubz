#include "MeshRenderer.h"

namespace graphics {
    MeshRenderer::MeshRenderer() {

    }

    void MeshRenderer::render(const graphics::Mesh &mesh) {
        // Bind Vertex Array
        m_vertexArray.bind();
        // Bind Vertex Buffer
        m_vertexBuffer.bind();
        m_vertexBuffer.update(mesh.vertices, false);
        // Bind Uv Buffer
        m_uvBuffer.bind();
        m_uvBuffer.update(mesh.uvs);
        // Bind Element Buffer
        m_elementBuffer.bind();
        m_elementBuffer.update(mesh.triangles);
        m_elementBuffer.draw();

        m_vertexBuffer.unbind();
        m_uvBuffer.unbind();
        m_elementBuffer.unbind();
    }
}