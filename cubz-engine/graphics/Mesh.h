#pragma once

#include <vector>

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <GL/glew.h>

namespace cubz::graphics {
    class Mesh {
    public:
        std::vector<glm::vec3> vertices;
        std::vector<glm::vec3> normals;
        std::vector<GLuint> triangles;
        std::vector<glm::vec2> uvs;

        void addVertex(const glm::vec3& vertex);
        void addQuadTriangles();
        void addQuadNormals(const glm::vec3& normal);
    };
}