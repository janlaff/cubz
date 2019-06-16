#pragma once

#include <glm/mat4x4.hpp>

namespace graphics {
    class Camera {
    public:
        Camera(int screenWidth, int screenHeight);

        glm::mat4 getModelViewProjection(const glm::mat4& model) const;
        glm::mat4 getTextProjection() const;

    private:
        glm::mat4 m_textProjection;
        glm::mat4 m_projection;
        glm::vec3 m_position;
        glm::vec3 m_head;
        glm::vec3 m_direction;
    };
}