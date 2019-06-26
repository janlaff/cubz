#pragma once

#include <vector>
#include <glm/vec3.hpp>

namespace core::opengl {
    class VertexQuadBuilder {
    public:
        void addVertex(const glm::vec3& vertex);
        void addQuadVertices();

        std::vector<glm::vec3> getQuadVertices() const;

    private:
        std::vector<glm::vec3> m_quadVertices;
        std::vector<glm::vec3> m_vertices;
    };
}