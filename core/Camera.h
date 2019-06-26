#pragma once

#include <glm/mat4x4.hpp>

namespace core {
    class Camera {
    public:
        Camera(int screenWidth, int screenHeight);

        void setPosition(const glm::vec3& position);
        void changeDirection(int deltaX, int deltaY);
        void moveForward();
        void moveBackward();
        void moveLeft();
        void moveRight();
        void setDeltaTime(float deltaTime);

        glm::mat4 getModelViewProjection(const glm::mat4& model) const;
        glm::mat4 getTextProjection() const;
        glm::vec3 getPosition() const;
        float getYaw() const;
        float getPitch() const;
        float getDeltaTime() const;

    private:
        glm::mat4 m_textProjection;
        glm::mat4 m_projection;
        glm::vec3 m_position;
        glm::vec3 m_direction;
        glm::vec3 m_right;
        float m_yaw;
        float m_pitch;
        float m_deltaTime;
        bool m_firstMouse;
    };
}