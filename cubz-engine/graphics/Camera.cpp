#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

namespace cubz::graphics {
    static const auto mouseSpeed = 2.5f;
    static const auto moveSpeed = 4.5f;

    Camera::Camera(int screenWidth, int screenHeight) {
        m_projection = glm::perspective(glm::radians(45.0f), float(screenWidth) / float(screenHeight), 0.1f, 100.0f);
        m_textProjection = glm::ortho(0.0f, float(screenWidth), 0.0f, float(screenHeight));
        m_transform = Transform {
            { 0, 0, 0 },
            glm::mat4(1.0f),
            glm::vec3(1.0f),
        };
    }

    void Camera::setTransform(const cubz::graphics::Transform &transform) {
        m_transform = transform;
    }

    glm::mat4 Camera::getModelViewProjection(const glm::mat4 &model) const {
        return m_projection * m_transform.rotation * model;
    }

    glm::mat4 Camera::getTextProjection() const {
        return m_textProjection;
    }
}