#pragma once

#include <string>
#include <GL/glew.h>
#include <glm/mat4x4.hpp>

namespace core::opengl {
    class Shader {
    public:
        Shader(const std::string& shaderName);

        void bind();
        void unbind();
        void enableVertexAttribArray(GLuint id);
        void disableVertexAttribArray(GLuint id);
        void setMat4(const std::string& name, const glm::mat4& mat);
        void setVec3(const std::string& name, const glm::vec3& vec);
        void setFloat(const std::string& name, GLfloat value);
        void setInt(const std::string& name, GLint value);

    private:
        std::string loadShader(const std::string& filename);
        void compileShader(GLuint shaderId, const std::string& shaderCode);
        void linkProgram(GLuint vertexShaderId, GLuint fragmentShaderId);

        GLuint m_programId;
    };
}