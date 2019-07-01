#pragma once

#include "opengl/Shader.h"
#include "opengl/Texture.h"
#include "opengl/CubeMap.h"
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
        opengl::CubeMap getCubeMap(const std::string& dir);
        ui::FreetypeCharMap generateCharMap(const std::string& name, int size);
        std::map<std::string, opengl::Shader> getShaders();

    private:
        std::map<std::string, opengl::Shader> m_shaders;
        std::map<std::string, opengl::Texture> m_textures;
        std::map<std::string, opengl::CubeMap> m_cubeMaps;
        std::string m_assetsDir;
        ui::FreetypeContext m_freetypeContext;
    };
}