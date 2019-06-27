#include "ComponentManager.h"

namespace cubz::ecs {
    void ComponentManager::entityDestroyed(Entity entity) {
        for (const auto& [typeName, component] : m_componentArrays) {
            component->entityDestroyed(entity);
        }
    }

    void ComponentManager::validateComponent(const char* typeName) {
        if (m_componentTypes.find(typeName) == m_componentTypes.end()) {
            throw std::runtime_error("Component type " + std::string(typeName) + " is not registered");
        }
    }
}