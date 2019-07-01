#pragma once

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

namespace cubz::graphics {
    struct Gravity {
        glm::vec3 force;
    };

    struct RigidBody {
        glm::vec3 velocity;
        glm::vec3 acceleration;
    };

    struct Transform {
        glm::vec3 position;
        glm::mat4 rotation;
        glm::vec3 scale;
    };
}