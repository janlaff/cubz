#include "MeshRenderer.h"

namespace graphics {
    MeshRenderer::MeshRenderer() {

    }

    void MeshRenderer::render(const graphics::Mesh &mesh) {
        m_vertexBuffer.bind();
        m_vertexBuffer.update(mesh.vertices);
        m_elementBuffer.bind();
        m_elementBuffer.update(mesh.triangles);

        m_vertexBuffer.draw();
        m_elementBuffer.draw();

        m_vertexBuffer.unbind();
        m_elementBuffer.unbind();
    }
}