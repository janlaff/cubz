#include <Log.h>
#include "TorchRenderer.h"

namespace cubz::game {
    void TorchRenderer::render(const graphics::Camera &camera) {
        glDisable(GL_CULL_FACE);

        data->shader.bind();
        data->shader.setInt("disableLights", true);
        data->shader.unbind();

        MeshRenderer::render(camera);
        glEnable(GL_CULL_FACE);

        data->shader.bind();
        data->shader.setInt("disableLights", false);
        data->shader.unbind();
    }
}