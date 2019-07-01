#include "GameObject.h"

namespace cubz::core {
    GameObject::GameObject(Engine *engine)
            : m_engine(engine)
            , m_entityId(m_engine->getECS().createEntity()) {}

    GameObject::~GameObject() {
        m_engine->getECS().destroyEntity(m_entityId);
    }

    void GameObject::update(float deltaTime) {}

    void GameObject::updateEntity() {
        m_engine->getECS().updateEntity(m_entityId);
    }

    graphics::ResourceManager& GameObject::getResourceManager() {
        return m_engine->getResourceManager();
    }
}