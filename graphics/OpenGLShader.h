#pragma once

#include <string>
#include <GL/glew.h>

namespace graphics {
    class OpenGLShader {
    public:
        OpenGLShader(const std::string& shaderName);

        void bind();
        void unbind();

    private:
        std::string loadShader(const std::string& filename);
        void compileShader(GLuint shaderId, const std::string& shaderCode);
        void linkProgram(GLuint vertexShaderId, GLuint fragmentShaderId);

        GLuint m_programId;
    };
}