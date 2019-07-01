#include "GameObject.h"

namespace cubz::core {
    GameObject::GameObject(Engine *engine)
            : m_engine(engine)
            , m_entityId(m_engine->getECS().createEntity()) {
        start();
    }

    GameObject::~GameObject() {
        m_engine->getECS().destroyEntity(m_entityId);
    }

    void GameObject::start() {}
    void GameObject::update(float deltaTime) {}

    graphics::ResourceManager& GameObject::getResourceManager() {
        return m_engine->getResourceManager();
    }
}