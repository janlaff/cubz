#pragma once

#include "GameObject.h"
#include "Camera.h"

namespace cubz::core {
    class Player : public GameObject {
    public:
        Player(Engine* engine);

        void updateView(float deltaX, float deltaY, float deltaTime);
        void updatePosition(float forward, float side, float deltaTime);
        void setPosition(const glm::vec3& position);
        void lookAt(const glm::vec3& target);

    private:
        float m_yaw;
        float m_pitch;
        bool m_firstMouse;
        glm::vec3 m_direction;
        glm::vec3 m_right;
    };
}