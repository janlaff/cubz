#pragma once

#include "opengl/Shader.h"
#include "opengl/Texture.h"
#include "ui/FreetypeContext.h"

#include <map>
#include <string>

namespace cubz::graphics {
    class ResourceManager {
    public:
        ResourceManager(const std::string& assetsDir);

        std::string getAssetsDir() const;
        opengl::Shader getShader(const std::string& name);
        opengl::Texture getTexture(const std::string& texture);
        ui::FreetypeCharMap generateCharMap(const std::string& name, int size);

    private:
        std::map<std::string, opengl::Shader> m_shaders;
        std::map<std::string, opengl::Texture> m_textures;
        std::string m_assetsDir;
        ui::FreetypeContext m_freetypeContext;
    };
}