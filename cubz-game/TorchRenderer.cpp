#include <Log.h>
#include "TorchRenderer.h"

namespace cubz::game {
    void TorchRenderer::render(const graphics::Camera &camera, const glm::vec3 &position) {
        glDisable(GL_CULL_FACE);

        m_shader.bind();
        m_shader.setInt("disableLights", true);
        m_shader.unbind();

        MeshRenderer::render(camera, position);
        glEnable(GL_CULL_FACE);

        m_shader.bind();
        m_shader.setInt("disableLights", false);
        m_shader.unbind();
    }
}