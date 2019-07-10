#pragma once

#include <glm/mat4x4.hpp>

#include "BasicComponents.h"

namespace cubz::graphics {
    class Camera {
    public:
        struct Properties {
            float zNear;
            float zFar;
        };

        Camera(int screenWidth, int screenHeight, const Properties props = { 0.1f, 100.0f });

        void setTransform(const Transform& transform);

        glm::mat4 getModelViewProjection(const glm::mat4& model) const;
        glm::mat4 getTextProjection() const;
        glm::mat4 getView() const;
        glm::mat4 getProjection() const;

    private:
        glm::mat4 m_textProjection;
        glm::mat4 m_projection;
        Transform m_transform;
    };
}