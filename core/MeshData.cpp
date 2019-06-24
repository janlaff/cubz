#include "MeshData.h"

namespace core {
    void MeshData::addQuadTriangles() {
        // Triangle 1
        triangles.push_back(vertices.size() - 4);
        triangles.push_back(vertices.size() - 2);
        triangles.push_back(vertices.size() - 1);

        // Triangle 2
        triangles.push_back(vertices.size() - 4);
        triangles.push_back(vertices.size() - 3);
        triangles.push_back(vertices.size() - 2);
    }
}