#include "Model.h"

#include <glm/gtc/matrix_transform.hpp>

namespace graphics {
    Model::Model(const std::string &shader, const std::string& texture)
        : m_shader(shader)
        , m_position(0, 0, 0)
        , m_texture(texture) {}

    void Model::render(const graphics::Camera &camera) {
        m_shader.bind();
        m_shader.enableVertexAttribArray(0);
        m_shader.enableVertexAttribArray(1);
        m_shader.setMVP(camera.getModelViewProjection(glm::translate(glm::mat4(1.0f), m_position)));
        m_texture.bind();
        m_meshRenderer.render(m_mesh);
        m_texture.unbind();
        m_shader.disableVertexAttribArray(1);
        m_shader.disableVertexAttribArray(0);
        m_shader.unbind();
    }
}