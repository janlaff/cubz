#pragma once

#include <map>

#include "opengl/Shader.h"

namespace graphics {
    class ShaderManager {
    public:
        ShaderManager();

        opengl::Shader getShader(const std::string& name);
    private:
        std::map<std::string, opengl::Shader> m_shaders;
    };
}