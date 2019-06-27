#pragma once

// STL
#include <array>
#include <unordered_map>

// Cubz
#include "Entity.h"

namespace cubz::ecs {
    class IComponentArray {
    public:
        virtual ~IComponentArray() = default;
        virtual void entityDestroyed(Entity entity) = 0;
    };

    template<typename T>
    class ComponentArray : public IComponentArray {
    public:
        void insertData(Entity entity, T component);
        void removeData(Entity entity);
        T& getData(Entity entity);
        void entityDestroyed(Entity entity) override;

    private:
        void validateEntity(Entity entity);

        std::array<T, MAX_ENTITIES> m_componentArray;
        std::unordered_map<Entity, size_t> m_entityToIndexMap;
        std::unordered_map<size_t, Entity> m_indexToEntityMap;
        std::size_t m_size = 0u;
    };
}

#include "ComponentArray.impl.h"