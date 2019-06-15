#include "OpenGLShader.h"
#include "Log.h"

#include <fstream>
#include <sstream>
#include <vector>

using namespace std::string_literals;

namespace graphics {
    OpenGLShader::OpenGLShader(const std::string &shaderName) {
        GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
        GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

        auto vertexShaderCode = loadShader(shaderName + ".vert");
        auto fragmentShaderCode = loadShader(shaderName + ".frag");

        utility::Log::debug("Compiling shader " + shaderName + ".vert");
        compileShader(vertexShaderId, vertexShaderCode);

        utility::Log::debug("Compiling shader " + shaderName + ".frag");
        compileShader(fragmentShaderId, fragmentShaderCode);

        utility::Log::debug("Linking program");
        linkProgram(vertexShaderId, fragmentShaderId);
    }

    std::string OpenGLShader::loadShader(const std::string &filename) {
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

    void OpenGLShader::compileShader(GLuint shaderId, const std::string& shaderCode) {
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

    void OpenGLShader::linkProgram(GLuint vertexShaderId, GLuint fragmentShaderId) {
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

    void OpenGLShader::bind() {
        glUseProgram(m_programId);
    }

    void OpenGLShader::unbind() {
        glUseProgram(0);
    }
}