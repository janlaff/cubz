#include "VertexQuadBuilder.h"

namespace cubz::graphics::opengl {
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

    void VertexQuadBuilder::addQuadUVs() {
        m_quadUVs.emplace_back(0.0f, 0.0f);
        m_quadUVs.emplace_back(1.0f, 1.0f);
        m_quadUVs.emplace_back(0.0f, 1.0f);

        m_quadUVs.emplace_back(0.0f, 0.0f);
        m_quadUVs.emplace_back(1.0f, 0.0f);
        m_quadUVs.emplace_back(1.0f, 1.0f);
    }

    std::vector<glm::vec2> VertexQuadBuilder::getQuadUVs() const {
        return m_quadUVs;
    }

    std::vector<glm::vec3> VertexQuadBuilder::getQuadVertices() const {
        return m_quadVertices;
    }
}