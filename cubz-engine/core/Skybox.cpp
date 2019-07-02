#include "Skybox.h"
#include "SkyboxRenderer.h"

namespace cubz::core {
    Skybox::Skybox(cubz::core::Engine *engine) : GameObject(engine) {
        addComponent<cubz::graphics::SkyboxRenderer>(cubz::graphics::SkyboxRenderer {
                getResourceManager().getCubeMap("skybox"),
                getResourceManager().getShader("skybox")
        });
    }
}