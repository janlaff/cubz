#pragma once

#include "opengl/Shader.h"
#include "opengl/Texture.h"
#include "ui/FreetypeContext.h"
#include "ui/FreetypeFont.h"

#include <map>
#include <string>

namespace core {
    class ResourceManager {
    public:
        static ResourceManager& getInstance();

        opengl::Shader getShader(const std::string& name);
        opengl::Texture getTexture(const std::string& texture);
        ui::FreetypeFont generateFont(const std::string& name, int size);
    private:
        ResourceManager();

        static ResourceManager instance;
        std::map<std::string, opengl::Shader> m_shaders;
        std::map<std::string, opengl::Texture> m_textures;
        ui::FreetypeContext m_freetypeContext;
    };
}