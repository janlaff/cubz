#include "Mesh.h"

namespace core {
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
        addQuadUvs();
    }

    void Mesh::addBottom() {
        vertices.emplace_back(-1.0f, -1.0f, 1.0f);
        vertices.emplace_back(1.0f, -1.0f, 1.0f);
        vertices.emplace_back(1.0f, -1.0f, -1.0f);
        vertices.emplace_back(-1.0f, -1.0f, -1.0f);

        addQuadTriangles();
        addQuadUvs();
    }

    void Mesh::addFront() {
        vertices.emplace_back(-1.0f, 1.0f, 1.0f);
        vertices.emplace_back(1.0f, 1.0f, 1.0f);
        vertices.emplace_back(1.0f, -1.0f, 1.0f);
        vertices.emplace_back(-1.0f, -1.0f, 1.0f);

        addQuadTriangles();
        addQuadUvs();
    }

    void Mesh::addBack() {
        vertices.emplace_back(1.0f, 1.0f, -1.0f);
        vertices.emplace_back(-1.0f, 1.0f, -1.0f);
        vertices.emplace_back(-1.0f, -1.0f, -1.0f);
        vertices.emplace_back(1.0f, -1.0f, -1.0f);

        addQuadTriangles();
        addQuadUvs();
    }

    void Mesh::addLeft() {
        vertices.emplace_back(-1.0f, 1.0f, -1.0f);
        vertices.emplace_back(-1.0f, 1.0f, 1.0f);
        vertices.emplace_back(-1.0f, -1.0f, 1.0f);
        vertices.emplace_back(-1.0f, -1.0f, -1.0f);

        addQuadTriangles();
        addQuadUvs();
    }

    void Mesh::addRight() {
        vertices.emplace_back(1.0f, 1.0f, 1.0f);
        vertices.emplace_back(1.0f, 1.0f, -1.0f); //
        vertices.emplace_back(1.0f, -1.0f, -1.0f);
        vertices.emplace_back(1.0f, -1.0f, 1.0f);

        addQuadTriangles();
        addQuadUvs();
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

    void Mesh::addQuadUvs() {
        uvs.emplace_back(0.0f, 1.0f);
        uvs.emplace_back(1.0f, 1.0f);
        uvs.emplace_back(1.0f, 0.0f);
        uvs.emplace_back(0.0f, 0.0f);
    }
}