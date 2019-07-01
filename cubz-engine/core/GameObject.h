#pragma once

#include "Engine.h"

namespace cubz::core {
    class GameObject {
    public:
        explicit GameObject(Engine* engine);
        ~GameObject();

        virtual void update(float deltaTime);

        template<typename T>
        void addComponent(T component);

        template<typename T>
        void removeComponent();

        template<typename T>
        T& getComponent();

        void updateEntity();

        graphics::ResourceManager& getResourceManager();

    private:
        Engine* m_engine;
        ecs::Entity m_entityId;
    };
}

#include "GameObject.impl.h"