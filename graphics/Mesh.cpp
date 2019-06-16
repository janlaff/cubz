#include "Mesh.h"

namespace graphics {
    void Mesh::addTop() {
        m_vertices.emplace_back(-1.0f, 1.0f, -1.0f);
        m_vertices.emplace_back(1.0f, 1.0f, -1.0f);
        m_vertices.emplace_back(1.0f, 1.0f, 1.0f);
        m_vertices.emplace_back(-1.0f, 1.0f, 1.0f);
    }

    void Mesh::addBottom() {
        m_vertices.emplace_back(-1.0f, -1.0f, 1.0f);
        m_vertices.emplace_back(1.0f, -1.0f, 1.0f);
        m_vertices.emplace_back(1.0f, -1.0f, -1.0f);
        m_vertices.emplace_back(-1.0f, -1.0f, -1.0f);
    }

    void Mesh::addQuadTriangles() {
        // Triangle 1
        m_triangles.push_back(m_vertices.size() - 4);
        m_triangles.push_back(m_vertices.size() - 2);
        m_triangles.push_back(m_vertices.size() - 1);

        // Triangle 2
        m_triangles.push_back(m_vertices.size() - 4);
        m_triangles.push_back(m_vertices.size() - 3);
        m_triangles.push_back(m_vertices.size() - 1);
    }
}