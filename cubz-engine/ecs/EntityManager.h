#pragma once

// STL
#include <queue>
#include <array>

// Cubz
#include "Entity.h"

namespace cubz::ecs {
    class EntityManager {
    public:
        EntityManager();

        Entity createEntity();
        void destroyEntity(Entity entity);
        void setSignature(Entity entity, Signature signature);
        Signature getSignature(Entity entity);

    private:
        void validateEntity(Entity entity);

        std::array<Signature, MAX_ENTITIES> m_signatures;
        std::queue<Entity> m_availableEntities;
        std::size_t m_entityCount;
    };
}