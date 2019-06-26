#include <Log.h>
#include "TorchRenderer.h"

namespace core {
    void TorchRenderer::render(const core::Camera &camera, const glm::vec3 &position) {
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