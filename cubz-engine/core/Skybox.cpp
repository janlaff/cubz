#include "Skybox.h"
#include "SkyboxRenderer.h"

namespace cubz::core {
    Skybox::Skybox(cubz::core::Engine *engine, std::string cubeMap) : GameObject(engine) {
        addComponent<cubz::graphics::SkyboxRenderer>(cubz::graphics::SkyboxRenderer {
                getResourceManager().getCubeMap(cubeMap),
                getResourceManager().getShader("skybox")
        });
    }
}