#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

namespace graphics {
    static const auto mouseSpeed = 2.5f;
    static const auto moveSpeed = 2.5f;

    Camera::Camera(int screenWidth, int screenHeight) {
        m_projection = glm::perspective(glm::radians(45.0f), float(screenWidth) / float(screenHeight), 0.1f, 100.0f);
        m_position = glm::vec3(0.0f, 0.0, 0.0f);
        m_right = glm::vec3(0.0f, 1.0f, 0.0f);
        m_direction = glm::vec3(4, 3, 3);
        m_textProjection = glm::ortho(0.0f, float(screenWidth), 0.0f, float(screenHeight));
        m_yaw = 0.0f;
        m_pitch = 0.0f;
        m_firstMouse = true;
    }

    void Camera::changeDirection(int deltaX, int deltaY, float deltaTime) {
        if (!m_firstMouse) {
            m_yaw += mouseSpeed * deltaTime * deltaX;
            m_pitch += mouseSpeed * deltaTime * deltaY;
        } else {
            m_firstMouse = false;
        }

        m_pitch = glm::clamp(m_pitch, -89.0f, 89.0f);

        m_direction = glm::vec3(
                cos(glm::radians(m_pitch)) * cos(glm::radians(m_yaw)),
                sin(glm::radians(m_pitch)),
                cos(glm::radians(m_pitch)) * sin(glm::radians(m_yaw))
        );
        m_right = glm::normalize(glm::cross(glm::vec3(0, 1, 0), m_direction));
    }

    void Camera::moveForward(float deltaTime) {
        m_position += m_direction * moveSpeed * deltaTime;
    }

    void Camera::moveBackward(float deltaTime) {
        m_position -= m_direction * moveSpeed * deltaTime;
    }

    void Camera::moveLeft(float deltaTime) {
        m_position += m_right * moveSpeed * deltaTime;
    }

    void Camera::moveRight(float deltaTime) {
        m_position -= m_right * moveSpeed * deltaTime;
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