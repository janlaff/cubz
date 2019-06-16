#pragma once

#include <string>
#include <GL/glew.h>
#include <glm/mat4x4.hpp>

namespace graphics::opengl {
    class Shader {
    public:
        Shader(const std::string& shaderName);

        void bind();
        void unbind();
        void enableVertexAttribArray(GLuint id);
        void disableVertexAttribArray(GLuint id);
        void setMVP(const glm::mat4& mvp);

    private:
        std::string loadShader(const std::string& filename);
        void compileShader(GLuint shaderId, const std::string& shaderCode);
        void linkProgram(GLuint vertexShaderId, GLuint fragmentShaderId);

        GLuint m_programId;
    };
}