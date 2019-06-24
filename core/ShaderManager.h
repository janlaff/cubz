#pragma once

#include <map>

#include "opengl/Shader.h"

namespace core {
    class ShaderManager {
    public:
        static ShaderManager& getInstance();

        opengl::Shader getShader(const std::string& name);
    private:
        ShaderManager();

        static ShaderManager instance;
        std::map<std::string, opengl::Shader> m_shaders;
    };
}