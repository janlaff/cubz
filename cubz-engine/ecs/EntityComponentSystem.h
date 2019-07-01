#pragma once

#include <memory>

// Cubz
#include "EntityManager.h"
#include "SystemManager.h"
#include "ComponentManager.h"

namespace cubz::ecs {
    class EntityComponentSystem {
    public:
        EntityComponentSystem();

        Entity createEntity();
        void destroyEntity(Entity entity);
        void updateEntity(Entity entity);

        template<typename T> void registerComponent();
        template<typename T> void addComponent(Entity entity, T component);
        template<typename T> void removeComponent(Entity entity);
        template<typename T> T& getComponent(Entity entity);
        template<typename T> ComponentType getComponentType();
        template<typename T> std::shared_ptr<T> registerSystem();
        template<typename T> void setSystemSignature(Signature signature);

    private:
        std::unique_ptr<EntityManager> m_entityManager;
        std::unique_ptr<ComponentManager> m_componentManager;
        std::unique_ptr<SystemManager> m_systemManager;
    };
}

#include "EntityComponentSystem.impl.h"