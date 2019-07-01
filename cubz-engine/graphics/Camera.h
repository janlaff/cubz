#pragma once

#include <glm/mat4x4.hpp>

#include "BasicComponents.h"

namespace cubz::graphics {
    class Camera {
    public:
        Camera(int screenWidth, int screenHeight);

        void setTransform(const Transform& transform);

        glm::mat4 getModelViewProjection(const glm::mat4& model) const;
        glm::mat4 getTextProjection() const;
        glm::vec3 getPosition() const;

    private:
        glm::mat4 m_textProjection;
        glm::mat4 m_projection;
        Transform m_transform;
    };
}