#pragma once

#include <vector>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

namespace cubz::graphics::opengl {
    class VertexQuadBuilder {
    public:
        void addVertex(const glm::vec3& vertex);
        void addQuadVertices();
        void addQuadUVs();

        std::vector<glm::vec3> getQuadVertices() const;
        std::vector<glm::vec2> getQuadUVs() const;

    private:
        std::vector<glm::vec3> m_quadVertices;
        std::vector<glm::vec2> m_quadUVs;
        std::vector<glm::vec3> m_vertices;
    };
}