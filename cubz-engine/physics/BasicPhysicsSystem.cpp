/*#include "BasicPhysicsSystem.h"
#include "BasicComponents.h"

namespace cubz::physics {
    void BasicPhysicsSystem::update(float deltaTime) {
        for (const auto& entity : m_entities) {
            auto& rigidBody = m_ecs->getComponent<cubz::graphics::RigidBody>(entity);
            auto& transform = m_ecs->getComponent<cubz::graphics::Transform>(entity);
            auto& gravity = m_ecs->getComponent<cubz::graphics::Gravity>(entity);

            transform.position += rigidBody.velocity * deltaTime;
            rigidBody.velocity += gravity.force * deltaTime;
        }
    }
}*/