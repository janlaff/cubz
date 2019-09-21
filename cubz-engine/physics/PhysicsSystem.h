#pragma once

#include "EntityComponentSystem.h"

#include <btBulletDynamicsCommon.h>

namespace cubz::physics {
    class PhysicsSystem : public ecs::System {
    public:
        explicit PhysicsSystem(ecs::EntityComponentSystem* ecs);

    private:
        std::shared_ptr<btDefaultCollisionConfiguration> m_collisionConfiguration;
        std::shared_ptr<btCollisionDispatcher> m_collisionDispatcher;
        std::shared_ptr<btBroadphaseInterface> m_broadphaseInterface;
        std::shared_ptr<btSequentialImpulseConstraintSolver> m_solver;
        std::shared_ptr<btDynamicsWorld> m_dynamicsWorld;
    };
}