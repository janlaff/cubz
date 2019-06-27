#include "EntityComponentSystem.h"

namespace cubz::ecs {
    EntityComponentSystem::EntityComponentSystem() {
        m_entityManager = std::make_unique<EntityManager>();
        m_componentManager = std::make_unique<ComponentManager>();
        m_systemManager = std::make_unique<SystemManager>();
    }

    Entity EntityComponentSystem::createEntity() {
        return m_entityManager->createEntity();
    }

    void EntityComponentSystem::destroyEntity(Entity entity) {
        m_entityManager->destroyEntity(entity);
        m_componentManager->entityDestroyed(entity);
        m_systemManager->entityDestroyed(entity);
    }
}