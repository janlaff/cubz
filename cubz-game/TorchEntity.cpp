#include "TorchEntity.h"
#include "TorchBlock.h"

#include <graphics/Mesh.h>
#include <graphics/MeshRenderer.h>
#include <graphics/BasicComponents.h>


namespace cubz::game {
    TorchEntity::TorchEntity(core::Engine *engine, const WorldPos& position) : GameObject(engine) {
        auto mesh = graphics::Mesh();

        TorchBlock().addSolidToMesh(mesh);

        addComponent<graphics::Mesh>(mesh);

        addComponent<graphics::MeshRenderer>(graphics::MeshRenderer(
                getResourceManager().getShader("mesh"),
                graphics::opengl::Material{
                        getResourceManager().getTexture("terrain.png"),
                        { 1, 1, 1 },
                        32
                }, true, true));

        addComponent<graphics::Transform>(graphics::Transform {
                position.toVec(),
                glm::mat4(1.0f),
                { 1, 1, 1 }
        });

        addComponent<graphics::PointLight>(graphics::PointLight {
                glm::vec3(0), // Overwritten by transform
                1.0f,//1.0f, 2.0f
                0.7f,//0.09f, 0.8f
                1.8f,//0.032f, 2.0f
                glm::vec3(0.1f),
                { 5.0f, 1.0f, 1.0f },
                { 5.0f, 1.0f, 1.0f },
                true
        });
    }

    void TorchEntity::update(float deltaTime) {
        // Dont do anything here
    }
}