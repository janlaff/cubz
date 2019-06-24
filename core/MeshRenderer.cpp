#include "MeshRenderer.h"

namespace core {
    MeshRenderer::MeshRenderer() {
        m_vertexArray.bind();
        m_vertexBuffer.bind();
        m_vertexBuffer.setAttribPointer();
        m_uvBuffer.bind();
        m_uvBuffer.setAttribPointer();
        m_elementBuffer.bind();
        m_elementBuffer.setAttribPointer();
        m_vertexArray.enableAttrib(0);
        m_vertexArray.enableAttrib(1);
        m_vertexArray.unbind();
    }

    void MeshRenderer::update(const Mesh& mesh) {
        m_vertexArray.bind();
        // Update vertices
        m_vertexBuffer.bind();
        m_vertexBuffer.update(mesh.vertices, false);
        m_vertexBuffer.setAttribPointer();
        // Update triangles
        m_elementBuffer.bind();
        m_elementBuffer.update(mesh.triangles);
        m_elementBuffer.setAttribPointer();
        // Update uvs
        m_uvBuffer.bind();
        m_uvBuffer.update(mesh.uvs);
        m_uvBuffer.setAttribPointer();

        m_vertexArray.unbind();
    }

    void MeshRenderer::render() {
        // Bind Vertex Array
        m_vertexArray.bind();
        m_elementBuffer.draw();
        m_vertexArray.unbind();
    }
}