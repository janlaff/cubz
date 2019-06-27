//#include "SystemManager.h"

namespace cubz::ecs {
    template<typename T>
    std::shared_ptr<T> SystemManager::registerSystem(EntityComponentSystem* ecs) {
        auto typeName = typeid(T).name();

        if (m_systems.find(typeName) != m_systems.end()) {
            throw std::runtime_error("System " + std::string(typeName) + " is already registered");
        }

        auto system = std::make_shared<T>(ecs);
        m_systems.insert({ typeName, system });
        return system;
    }

    template<typename T>
    void SystemManager::setSignature(Signature signature) {
        auto typeName = typeid(T).name();

        if (m_systems.find(typeName) == m_systems.end()) {
            throw std::runtime_error("System " + std::string(typeName) + " is not registered");
        }

        m_signatures.insert({ typeName, signature });
    }
}