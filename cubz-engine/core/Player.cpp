#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Log.h>
#include "Player.h"
#include "BasicComponents.h"

namespace cubz::core {
    Player::Player(Engine *engine)
            : GameObject(engine)
            , m_yaw(0.0f)
            , m_pitch(0.0f) {
        addComponent<graphics::Transform>(graphics::Transform {
            { 0, 0, 0 },
            glm::mat4(1.0f),
            glm::vec3(1.0f)
        });

    }

    void Player::updateView(float deltaX, float deltaY, float deltaTime) {
        const auto mouseSpeed = 10.0f;

        if (!m_firstMouse) {
            m_yaw += glm::clamp(mouseSpeed * deltaTime * deltaX, -180.0f, 180.0f);
            m_pitch += glm::clamp(mouseSpeed * deltaTime * deltaY, -90.0f, 90.0f);
        } else {
            m_yaw = 0;
            m_pitch = 0;
            m_firstMouse = false;
        }

        m_pitch = glm::clamp(m_pitch, -89.0f, 89.0f);

        if (m_yaw > 180.0f) {
            m_yaw = -360.0f + m_yaw;
        }

        if (m_yaw < -180.0f) {
            m_yaw = 360.0f - m_yaw;
        }

        m_direction = glm::normalize(glm::vec3 {
                cos(glm::radians(m_pitch)) * cos(glm::radians(m_yaw)),
                sin(glm::radians(m_pitch)),
                cos(glm::radians(m_pitch)) * sin(glm::radians(m_yaw))
        });

        m_right = glm::normalize(glm::cross(m_direction, glm::vec3(0, 1, 0)));

        lookAt(m_direction);
    }

    void Player::updatePosition(float forward, float side, float deltaTime) {
        const auto speed = 10.0f;

        auto& transform = getComponent<graphics::Transform>();

        transform.position -= forward * speed * deltaTime * m_direction;
        transform.position -= side * speed * deltaTime * m_right;
    }

    void Player::setPosition(const glm::vec3 &position) {
        auto& transform = getComponent<graphics::Transform>();
        transform.position = position;
    }

    void Player::lookAt(const glm::vec3 &target) {
        auto& transform = getComponent<graphics::Transform>();
        transform.rotation = glm::lookAt(transform.position, transform.position - target, { 0, 1, 0 });
    }
}