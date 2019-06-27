//#include "ComponentManager.h"

namespace cubz::ecs {
    template<typename T>
    void ComponentManager::registerComponent() {
        auto typeName = typeid(T).name();
        if (m_componentTypes.find(typeName) != m_componentTypes.end()) {
            throw std::runtime_error("Component " + std::string(typeName) + " already registered");
        }

        m_componentTypes.insert({ typeName, m_nextComponentType });
        m_componentArrays.insert({ typeName, std::make_shared<ComponentArray<T>>() });

        ++m_nextComponentType;
    }

    template<typename T>
    ComponentType ComponentManager::getComponentType() {
        auto typeName = typeid(T).name();
        validateComponent(typeName);

        return m_componentTypes[typeName];
    }

    template<typename T>
    void ComponentManager::addComponent(Entity entity, T component) {
        getComponentArray<T>()->insertData(entity, component);
    }

    template<typename T>
    void ComponentManager::removeComponent(Entity entity) {
        getComponentArray<T>()->removeData(entity);
    }

    template<typename T>
    T& ComponentManager::getComponent(Entity entity) {
        return getComponentArray<T>()->getData(entity);
    }

    template<typename T>
    std::shared_ptr<ComponentArray<T>> ComponentManager::getComponentArray() {
        auto typeName = typeid(T).name();
        validateComponent(typeName);

        return std::static_pointer_cast<ComponentArray<T>>(m_componentArrays[typeName]);
    }
}