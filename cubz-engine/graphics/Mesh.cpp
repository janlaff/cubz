#include "Mesh.h"

namespace cubz::graphics {
    void Mesh::addVertex(const glm::vec3 &vertex) {
        vertices.push_back(vertex);
    }

    void Mesh::addQuadTriangles() {
        // Triangle 1
        triangles.push_back(vertices.size() - 4);
        triangles.push_back(vertices.size() - 2);
        triangles.push_back(vertices.size() - 1);

        // Triangle 2
        triangles.push_back(vertices.size() - 4);
        triangles.push_back(vertices.size() - 3);
        triangles.push_back(vertices.size() - 2);
    }

    void Mesh::addQuadNormals(const glm::vec3 &normal) {
        for (int i = 0; i < 4; ++i) {
            normals.push_back(normal);
        }
    }
}