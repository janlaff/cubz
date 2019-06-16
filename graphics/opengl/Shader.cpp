#include "Shader.h"
#include "Log.h"

#include <fstream>
#include <sstream>
#include <vector>

using namespace std::string_literals;

namespace graphics::opengl {
    static const auto shaderDir = "./assets/shaders/";

    Shader::Shader(const std::string &shaderName) {
        GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
        GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

        auto vertexShaderCode = loadShader(shaderDir + shaderName + ".vert");
        auto fragmentShaderCode = loadShader(shaderDir + shaderName + ".frag");

        utility::Log::debug("Compiling shader " + shaderName + ".vert");
        compileShader(vertexShaderId, vertexShaderCode);

        utility::Log::debug("Compiling shader " + shaderName + ".frag");
        compileShader(fragmentShaderId, fragmentShaderCode);

        utility::Log::debug("Linking program");
        linkProgram(vertexShaderId, fragmentShaderId);
    }

    void Shader::enableVertexAttribArray(GLuint id) {
        glEnableVertexAttribArray(id);
    }

    void Shader::disableVertexAttribArray(GLuint id) {
        glDisableVertexAttribArray(id);
    }

    std::string Shader::loadShader(const std::string &filename) {
        auto fs = std::ifstream(filename);

        if (fs.is_open()) {
            auto ss = std::ostringstream();
            ss << fs.rdbuf();
            fs.close();

            return ss.str();
        } else {
            throw std::runtime_error("Failed to open file " + filename);
        }
    }

    void Shader::compileShader(GLuint shaderId, const std::string& shaderCode) {
        auto srcPtr = shaderCode.data();

        glShaderSource(shaderId, 1, &srcPtr, nullptr);
        glCompileShader(shaderId);

        auto result = 0;
        auto infoLogLength = 0;

        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &result);
        glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &infoLogLength);

        if (infoLogLength > 0) {
            std::vector<char> errorMessage(infoLogLength + 1);
            glGetShaderInfoLog(shaderId, infoLogLength, nullptr, errorMessage.data());

            throw std::runtime_error("Compilation failed\n"s + std::string(errorMessage.begin(), errorMessage.end()));
        }
    }

    void Shader::linkProgram(GLuint vertexShaderId, GLuint fragmentShaderId) {
        m_programId = glCreateProgram();
        glAttachShader(m_programId, vertexShaderId);
        glAttachShader(m_programId, fragmentShaderId);
        glLinkProgram(m_programId);

        auto result = 0;
        auto infoLogLength = 0;

        glGetProgramiv(m_programId, GL_LINK_STATUS, &result);
        glGetProgramiv(m_programId, GL_INFO_LOG_LENGTH, &infoLogLength);

        if (infoLogLength > 0) {
            std::vector<char> errorMessage(infoLogLength + 1);
            glGetProgramInfoLog(m_programId, infoLogLength, nullptr, errorMessage.data());

            throw std::runtime_error("Linking failed\n"s + std::string(errorMessage.begin(), errorMessage.end()));
        }

        glDetachShader(m_programId, vertexShaderId);
        glDetachShader(m_programId, fragmentShaderId);
        glDeleteShader(vertexShaderId);
        glDeleteShader(fragmentShaderId);
    }

    void Shader::bind() {
        glUseProgram(m_programId);
    }

    void Shader::unbind() {
        glUseProgram(0);
    }

    void Shader::setMVP(const glm::mat4 &mvp) {
        GLint mvpId = glGetUniformLocation(m_programId, "mvp");
        glUniformMatrix4fv(mvpId, 1, GL_FALSE, &mvp[0][0]);
    }
}