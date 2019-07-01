#include <graphics/Mesh.h>
#include <graphics/MeshRenderer.h>

#include "ChunkEntity.h"
#include "Block.h"

namespace cubz::game {
    ChunkEntity::ChunkEntity(cubz::core::Engine *engine) : GameObject(engine) {
        addComponent<graphics::Mesh>(graphics::Mesh());
        addComponent<ChunkData>(ChunkData());

        addComponent<graphics::MeshRenderer>(graphics::MeshRenderer(
                getResourceManager().getShader("mesh"),
                graphics::opengl::Material{
                        getResourceManager().getTexture("terrain.png"),
                        { 1, 1, 1 },
                        32
                }));

        addComponent<graphics::Transform>(graphics::Transform {
            { 0, 0, 0 },
            glm::mat4(1.0f),
            { 1, 1, 1 }
        });
    }

    void ChunkEntity::update(float deltaTime) {
        // Dont do anything here
    }
}