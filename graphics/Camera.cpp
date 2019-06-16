#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

namespace graphics {
    static const auto mouseSpeed = 0.3f;
    static const auto moveSpeed = 2.5f;

    Camera::Camera(int screenWidth, int screenHeight) {
        m_projection = glm::perspective(glm::radians(45.0f), float(screenWidth) / float(screenHeight), 0.1f, 100.0f);
        m_position = glm::vec3(0.0f, 0.0, 0.0f);
        m_right = glm::vec3(0.0f, 1.0f, 0.0f);
        m_direction = glm::vec3(4, 3, 3);
        m_textProjection = glm::ortho(0.0f, float(screenWidth), 0.0f, float(screenHeight));
    }

    void Camera::changeDirection(int deltaX, int deltaY, float deltaTime) {
        m_horizontalAngle += mouseSpeed * deltaTime * deltaX;
        m_verticalAngle += mouseSpeed * deltaTime * deltaY;
        m_direction = glm::vec3(
                cos(m_verticalAngle) * sin(m_horizontalAngle),
                sin(m_verticalAngle),
                cos(m_verticalAngle) * cos(m_horizontalAngle)
        );
        m_right = glm::vec3(
                sin(m_horizontalAngle - 3.14f/2.0f),
                0,
                cos(m_horizontalAngle - 3.14f/2.0f)
        );
    }

    void Camera::moveForward(float deltaTime) {
        m_position += m_direction * moveSpeed * deltaTime;
    }

    void Camera::moveBackward(float deltaTime) {
        m_position -= m_direction * moveSpeed * deltaTime;
    }

    void Camera::moveLeft(float deltaTime) {
        m_position -= m_right * moveSpeed * deltaTime;
    }

    void Camera::moveRight(float deltaTime) {
        m_position += m_right * moveSpeed * deltaTime;
    }

    void Camera::setPosition(const glm::vec3 &position) {
        m_position = position;
    }

    glm::mat4 Camera::getModelViewProjection(const glm::mat4 &model) const {
        auto view = glm::lookAt(
                m_position,
                m_position + m_direction,
                glm::vec3(0, 1, 0)
        );

        return m_projection * view * model;
    }

    glm::mat4 Camera::getTextProjection() const {
        return m_textProjection;
    }

    glm::vec3 Camera::getPosition() const {
        return m_position;
    }
}