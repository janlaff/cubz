#pragma once

#include <vector>

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <GL/glew.h>

namespace graphics {
    class Mesh {
    public:
        std::vector<glm::vec3> vertices;
        std::vector<GLuint> triangles;
        std::vector<glm::vec2> uvs;

        Mesh();

    private:
        void addTop();
        void addBottom();
        void addFront();
        void addBack();
        void addLeft();
        void addRight();
        void addQuadTriangles();
        void addQuadUvs();
    };
}