#include "EntityManager.h"

namespace cubz::ecs {
    EntityManager::EntityManager() : m_entityCount(0) {
        // Make all m_entities available
        for (auto entity = Entity(0); entity < MAX_ENTITIES; ++entity) {
            m_availableEntities.push(entity);
        }
    }

    Entity EntityManager::createEntity() {
        if (m_entityCount == MAX_ENTITIES) {
            throw std::runtime_error("Maximum entity count reached");
        }

        // Fetch entity that is available
        auto id = m_availableEntities.front();
        m_availableEntities.pop();
        ++m_entityCount;

        return id;
    }

    void EntityManager::destroyEntity(Entity entity) {
        validateEntity(entity);

        // Unregister all components
        m_signatures[entity].reset();
        // Make entity available again
        m_availableEntities.push(entity);
        --m_entityCount;
    }

    void EntityManager::setSignature(Entity entity, Signature signature) {
        validateEntity(entity);
        m_signatures[entity] = signature;
    }

    Signature EntityManager::getSignature(Entity entity) {
        validateEntity(entity);
        return m_signatures[entity];
    }

    void EntityManager::validateEntity(Entity entity) {
        if (entity >= MAX_ENTITIES) {
            throw std::runtime_error("Entity (" + std::to_string(entity) + ") out of range");
        }
    }
}