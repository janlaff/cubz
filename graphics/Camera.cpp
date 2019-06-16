#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace graphics {
    Camera::Camera(int screenWidth, int screenHeight) {
        m_projection = glm::perspective(glm::radians(45.0f), float(screenWidth) / float(screenHeight), 0.1f, 100.0f);
        m_position = glm::vec3(4, 3, 3);
        m_head = glm::vec3(0, 1, 0);
        m_direction = glm::vec3(0, 0, 0);
        m_textProjection = glm::ortho(0.0f, float(screenWidth), 0.0f, float(screenHeight));
    }

    glm::mat4 Camera::getModelViewProjection(const glm::mat4 &model) const {
        auto view = glm::lookAt(m_position, m_direction, m_head);

        return m_projection * view * model;
    }

    glm::mat4 Camera::getTextProjection() const {
        return m_textProjection;
    }
}