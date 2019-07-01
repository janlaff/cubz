#pragma once

// STL
#include <unordered_map>
#include <memory>
#include <set>

// Cubz
#include "Entity.h"

namespace cubz::ecs {
    class EntityComponentSystem;

    class System {
    public:
        explicit System(EntityComponentSystem* ecs);

        void addEntity(Entity entity);
        void removeEntity(Entity entity);
        void updateEntity(Entity entity);

    protected:
        std::set<Entity> m_entities;
        std::set<Entity> m_updatedEntities;
        EntityComponentSystem* m_ecs;
    };

    class SystemManager {
    public:
        template<typename T, typename ... Args> std::shared_ptr<T> registerSystem(EntityComponentSystem* ecs, Args&&... args);
        template<typename T> void setSignature(Signature signature);

        void entityDestroyed(Entity entity);
        void entitySignatureChanged(Entity entity, Signature entitySignature);
        void entityUpdated(Entity entity);

    private:
        std::unordered_map<const char*, Signature> m_signatures;
        std::unordered_map<const char*, std::shared_ptr<System>> m_systems;
    };
}

#include "SystemManager.impl.h"