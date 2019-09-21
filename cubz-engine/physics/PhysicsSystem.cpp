#include "PhysicsSystem.h"

namespace cubz::physics {
    PhysicsSystem::PhysicsSystem(cubz::ecs::EntityComponentSystem *ecs) : System(ecs) {
        /*m_collisionConfiguration = std::make_shared<btDefaultCollisionConfiguration>();
        m_collisionDispatcher = std::make_shared<btCollisionDispatcher>(m_collisionDispatcher.get());
        m_broadphaseInterface = std::make_shared<btDbvtBroadphase>();
        m_solver = std::make_shared<btSequentialImpulseConstraintSolver>();
        m_dynamicsWorld = std::make_shared<btDiscreteDynamicsWorld>(
                m_collisionDispatcher.get(),
                m_broadphaseInterface.get(),
                m_solver.get(),
                m_collisionConfiguration.get()
        );*/
    }
}