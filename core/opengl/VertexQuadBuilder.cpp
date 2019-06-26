#include "VertexQuadBuilder.h"

namespace core::opengl {
    void VertexQuadBuilder::addVertex(const glm::vec3 &vertex) {
        m_vertices.push_back(vertex);
    }

    void VertexQuadBuilder::addQuadVertices() {
        m_quadVertices.push_back(m_vertices[m_vertices.size() - 4]);
        m_quadVertices.push_back(m_vertices[m_vertices.size() - 2]);
        m_quadVertices.push_back(m_vertices[m_vertices.size() - 1]);

        m_quadVertices.push_back(m_vertices[m_vertices.size() - 4]);
        m_quadVertices.push_back(m_vertices[m_vertices.size() - 3]);
        m_quadVertices.push_back(m_vertices[m_vertices.size() - 2]);
    }

    std::vector<glm::vec3> VertexQuadBuilder::getQuadVertices() const {
        return m_quadVertices;
    }
}