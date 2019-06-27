//#include "ComponentArray.h"

namespace cubz::ecs {
    template<typename T>
    void ComponentArray<T>::insertData(Entity entity, T component) {
        if (m_entityToIndexMap.find(entity) != m_entityToIndexMap.end()) {
            throw std::runtime_error("Component already exists for entity (" + std::to_string(entity) + ")");
        }

        // Register component
        auto newIndex = m_size;
        m_entityToIndexMap[entity] = newIndex;
        m_indexToEntityMap[newIndex] = entity;
        m_componentArray[newIndex] = component;

        ++m_size;
    }

    template<typename T>
    void ComponentArray<T>::removeData(Entity entity) {
        validateEntity(entity);

        // Copy element at end into deleted element's place to maintain density
        auto removedEntityIndex = m_entityToIndexMap[entity];
        auto lastElementIndex = m_size - 1;
        m_componentArray[removedEntityIndex] = m_componentArray[lastElementIndex];

        // Update maps
        auto lastElementEntity = m_indexToEntityMap[lastElementIndex];
        m_entityToIndexMap[lastElementEntity] = removedEntityIndex;
        m_indexToEntityMap[removedEntityIndex] = lastElementEntity;

        m_entityToIndexMap.erase(entity);
        m_indexToEntityMap.erase(lastElementIndex);

        --m_size;
    }

    template<typename T>
    T& ComponentArray<T>::getData(Entity entity) {
        validateEntity(entity);

        return m_componentArray[m_entityToIndexMap[entity]];
    }

    template<typename T>
    void ComponentArray<T>::entityDestroyed(Entity entity) {
        if (m_entityToIndexMap.find(entity) != m_entityToIndexMap.end()) {
            removeData(entity);
        }
    }

    template<typename T>
    void ComponentArray<T>::validateEntity(Entity entity) {
        if (m_entityToIndexMap.find(entity) == m_entityToIndexMap.end()) {
            throw std::runtime_error("Non existent component for entity (" + std::to_string(entity) + ")");
        }
    }
}