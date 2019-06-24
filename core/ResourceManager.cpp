#include "ResourceManager.h"

namespace core {
    ResourceManager ResourceManager::instance;

    ResourceManager& ResourceManager::getInstance() {
        return instance;
    }

    ResourceManager::ResourceManager() {}

    opengl::Shader ResourceManager::getShader(const std::string &name) {
        if (auto it = m_shaders.find(name); it != m_shaders.end()) {
            return it->second;
        } else {
            auto tmp = m_shaders.insert({name, opengl::Shader(name)}).first;
            return tmp->second;
        }
    }

    opengl::Texture ResourceManager::getTexture(const std::string &name) {
        if (auto it = m_textures.find(name); it != m_textures.end()) {
            return it->second;
        } else {
            auto tmp = m_textures.insert({name, opengl::Texture(name)}).first;
            return tmp->second;
        }
    }
}