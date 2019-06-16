#pragma once

namespace graphics {
    class Model {
    public:
        Model(const std::string& shader);

    private:
        opengl::Shader m_shader;
        opengl::VertexBuffer m_vertexBuffer;
    };
}