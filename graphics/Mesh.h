#pragma once

#include <vector>

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

namespace graphics {
    class Mesh {
    public:
        std::vector<glm::vec3> vertices;
        std::vector<int> triangles;
        std::vector<glm::vec3> uvs;

        Mesh();

    private:
        void addTop();
        void addBottom();
        void addFront();
        void addBack();
        void addLeft();
        void addRight();
        void addQuadTriangles();
    };
}