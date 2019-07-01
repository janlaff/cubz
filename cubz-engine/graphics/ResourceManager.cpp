#include "ResourceManager.h"

namespace cubz::graphics {
    ResourceManager::ResourceManager(const std::string &assetsDir)
            : m_assetsDir(assetsDir)
            , m_freetypeContext(getShader("text")) {
        // Early load mesh shader
        getShader("mesh");
    }


    std::string ResourceManager::getAssetsDir() const {
        return m_assetsDir;
    }

    opengl::Shader ResourceManager::getShader(const std::string &name) {
        if (auto it = m_shaders.find(name); it != m_shaders.end()) {
            return it->second;
        } else {
            auto tmp = m_shaders.insert({name, opengl::Shader(m_assetsDir + "/shaders/" + name)}).first;
            return tmp->second;
        }
    }

    opengl::Texture ResourceManager::getTexture(const std::string &name) {
        if (auto it = m_textures.find(name); it != m_textures.end()) {
            return it->second;
        } else {
            auto tmp = m_textures.insert({name, opengl::Texture(m_assetsDir + "/textures/" + name)}).first;
            return tmp->second;
        }
    }

    opengl::CubeMap ResourceManager::getCubeMap(const std::string &dir) {
        if (auto it = m_cubeMaps.find(dir); it != m_cubeMaps.end()) {
            return it->second;
        } else {
            auto tmp = m_cubeMaps.insert({dir, opengl::CubeMap(m_assetsDir + "/textures/" + dir + "/")}).first;
            return tmp->second;
        }
    }

    ui::FreetypeCharMap ResourceManager::generateCharMap(const std::string &name, int size) {
        return m_freetypeContext.generateCharMap(m_assetsDir + "/fonts/" + name, size);
    }

    std::map<std::string, opengl::Shader> ResourceManager::getShaders() {
        return m_shaders;
    }
}