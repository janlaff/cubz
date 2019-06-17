#pragma once

#include <glm/mat4x4.hpp>

namespace graphics {
    class Camera {
    public:
        Camera(int screenWidth, int screenHeight);

        void setPosition(const glm::vec3& position);
        void changeDirection(int deltaX, int deltaY, float deltaTime);
        void moveForward(float deltaTime);
        void moveBackward(float deltaTime);
        void moveLeft(float deltaTime);
        void moveRight(float deltaTime);

        glm::mat4 getModelViewProjection(const glm::mat4& model) const;
        glm::mat4 getTextProjection() const;
        glm::vec3 getPosition() const;

    private:
        glm::mat4 m_textProjection;
        glm::mat4 m_projection;
        glm::vec3 m_position;
        glm::vec3 m_direction;
        glm::vec3 m_right;
        float m_yaw;
        float m_pitch;
        bool m_firstMouse;
    };
}