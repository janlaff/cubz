#include "ShaderManager.h"

namespace graphics {
    ShaderManager ShaderManager::instance;

    ShaderManager& ShaderManager::getInstance() {
        return instance;
    }

    ShaderManager::ShaderManager() {}

    opengl::Shader ShaderManager::getShader(const std::string &name) {
        if (auto it = m_shaders.find(name); it != m_shaders.end()) {
            return it->second;
        } else {
            auto tmp = m_shaders.insert({name, opengl::Shader(name)}).first;
            return tmp->second;
        }
    }
}