#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

namespace cubz::graphics {
    static const auto mouseSpeed = 2.5f;
    static const auto moveSpeed = 4.5f;

    Camera::Camera(int screenWidth, int screenHeight) {
        m_projection = glm::perspective(glm::radians(45.0f), float(screenWidth) / float(screenHeight), 0.1f, 100.0f);
        m_position = glm::vec3(0.0f, 0.0, 0.0f);
        m_right = glm::vec3(0.0f, 1.0f, 0.0f);
        m_direction = glm::vec3(0, 0, 0);
        m_textProjection = glm::ortho(0.0f, float(screenWidth), 0.0f, float(screenHeight));
    }

    void Camera::lookAt(const glm::vec3 &position) {
        m_direction = m_position - position;
    }

    void Camera::setPosition(const glm::vec3 &position) {
        m_position = position;
    }

    void Camera::setDirection(const glm::vec3& direction) {
        m_direction = direction;
        m_right = glm::normalize(glm::cross(glm::vec3(0, 1, 0), m_direction));
    }

    glm::mat4 Camera::getModelViewProjection(const glm::mat4 &model) const {
        /*auto view = glm::lookAt(
                m_position,
                m_position + m_direction,
                glm::vec3(0, 1, 0)
        );*/

        auto view = glm::lookAt(
                glm::vec3 { 4, 3, 3 },
                glm::vec3 { 0, 0, 0 },
                glm::vec3 { 0, 1, 0 }
        );

        return m_projection * view * model;
    }

    glm::mat4 Camera::getTextProjection() const {
        return m_textProjection;
    }

    glm::vec3 Camera::getPosition() const {
        return m_position;
    }

    glm::vec3 Camera::getDirection() const {
        return m_direction;
    }
}