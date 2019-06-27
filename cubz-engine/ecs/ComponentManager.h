#pragma once

// STL
#include <memory>

// Cubz
#include "ComponentArray.h"

namespace cubz::ecs {
    class ComponentManager {
    public:
        template<typename T> void registerComponent();
        template<typename T> ComponentType getComponentType();
        template<typename T> void addComponent(Entity entity, T component);
        template<typename T> void removeComponent(Entity entity);
        template<typename T> T& getComponent(Entity entity);

        void entityDestroyed(Entity entity);

    private:
        template<typename T> std::shared_ptr<ComponentArray<T>> getComponentArray();

        void validateComponent(const char* typeName);

        std::unordered_map<const char*, ComponentType> m_componentTypes;
        std::unordered_map<const char*, std::shared_ptr<IComponentArray>> m_componentArrays;
        ComponentType m_nextComponentType;
    };
}

#include "ComponentManager.impl.h"