#include <Log.h>
#include "TorchRenderer.h"

namespace core {
    void TorchRenderer::render(const core::Camera &camera, const glm::vec3 &position) {
        glDisable(GL_CULL_FACE);

        m_shader.bind();
        m_shader.setInt("disableLights", true);
        int i = 0;
        for (auto [pos, light] : m_lights) {
            light.bind(m_shader, i++);
        }
        m_shader.unbind();

        Renderer::render(camera, position);
        glEnable(GL_CULL_FACE);

        m_shader.bind();
        m_shader.setInt("disableLights", false);
        m_shader.unbind();
    }

    void TorchRenderer::addTorch(const core::WorldPos &position) {
        auto pos = position.toVec();

        pos.y += 0.6f;

        m_lights.insert({ position, opengl::PointLight{
            pos,
            1.0f,
            0.09f,
            0.032f,
            glm::vec3(0.1f),
            { 1.0f, 1.0f, 0.0f },
            { 1.0f, 1.0f, 0.0f },
            true
        } });
    }

    void TorchRenderer::clearTorchs() {
        m_lights.clear();
    }

    void TorchRenderer::removeTorch(const core::WorldPos &position) {
        if (auto light = m_lights.find(position); light != m_lights.end()) {
            m_lights.erase(light);
        } else {
            utility::Log::warning("Failed to remove torch");
        }
    }
}