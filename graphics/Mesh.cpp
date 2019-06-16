#include "Mesh.h"

namespace graphics {
    Mesh::Mesh() {
        // TODO: this is for testing purposes only
        addTop();
        addBottom();
        addLeft();
        addRight();
        addFront();
        addBack();
    }

    void Mesh::addTop() {
        vertices.emplace_back(-1.0f, 1.0f, -1.0f);
        vertices.emplace_back(1.0f, 1.0f, -1.0f);
        vertices.emplace_back(1.0f, 1.0f, 1.0f);
        vertices.emplace_back(-1.0f, 1.0f, 1.0f);

        addQuadTriangles();
    }

    void Mesh::addBottom() {
        vertices.emplace_back(-1.0f, -1.0f, 1.0f);
        vertices.emplace_back(1.0f, -1.0f, 1.0f);
        vertices.emplace_back(1.0f, -1.0f, -1.0f);
        vertices.emplace_back(-1.0f, -1.0f, -1.0f);

        addQuadTriangles();
    }

    void Mesh::addFront() {
        vertices.emplace_back(-1.0f, 1.0f, 1.0f);
        vertices.emplace_back(1.0f, 1.0f, 1.0f);
        vertices.emplace_back(1.0f, -1.0f, 1.0f);
        vertices.emplace_back(-1.0f, -1.0f, 1.0f);

        addQuadTriangles();
    }

    void Mesh::addBack() {
        vertices.emplace_back(1.0f, 1.0f, -1.0f);
        vertices.emplace_back(-1.0f, 1.0f, -1.0f);
        vertices.emplace_back(-1.0f, -1.0f, -1.0f);
        vertices.emplace_back(1.0f, -1.0f, -1.0f);

        addQuadTriangles();
    }

    void Mesh::addLeft() {
        vertices.emplace_back(-1.0f, 1.0f, -1.0f);
        vertices.emplace_back(-1.0f, 1.0f, 1.0f);
        vertices.emplace_back(-1.0f, -1.0f, 1.0f);
        vertices.emplace_back(-1.0f, -1.0f, -1.0f);

        addQuadTriangles();
    }

    void Mesh::addRight() {
        vertices.emplace_back(1.0f, 1.0f, 1.0f);
        vertices.emplace_back(1.0f, 1.0f, -1.0f);
        vertices.emplace_back(1.0f, -1.0f, -1.0f);
        vertices.emplace_back(1.0f, -1.0f, 1.0f);

        addQuadTriangles();
    }

    void Mesh::addQuadTriangles() {
        // Triangle 1
        triangles.push_back(vertices.size() - 4);
        triangles.push_back(vertices.size() - 2);
        triangles.push_back(vertices.size() - 1);

        // Triangle 2
        triangles.push_back(vertices.size() - 4);
        triangles.push_back(vertices.size() - 3);
        triangles.push_back(vertices.size() - 1);
    }
}