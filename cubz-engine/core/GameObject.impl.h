//#include "GameObject.h"

namespace cubz::core {
    template<typename T>
    void GameObject::addComponent(T component) {
        m_engine->getECS().addComponent<T>(m_entityId, component);
    }

    template<typename T>
    void GameObject::removeComponent() {
        m_engine->getECS().removeComponent<T>(m_entityId);
    }

    template<typename T>
    T& GameObject::getComponent() {
        return m_engine->getECS().getComponent<T>(m_entityId);
    }
}