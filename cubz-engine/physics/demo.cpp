#include <ConsoleLogger.h>
#include <Log.h>
#include <Screen.h>
#include <Mesh.h>
#include <ecs/EntityComponentSystem.h>
#include <opengl/Material.h>
#include <opengl/VertexBuffer.h>
#include <opengl/UVBuffer.h>
#include <opengl/NormalBuffer.h>
#include <opengl/ElementBuffer.h>
#include <opengl/VertexArray.h>
#include <BasicComponents.h>
#include <MeshRenderer.h>

class PhysicsSystem : public cubz::graphics::ecs::System {
public:

};

class RenderSystem : public cubz::graphics::ecs::System {
public:
    using cubz::graphics::ecs::System::System;

    void update() {
        for (const auto& entity : entities) {
            const auto& mesh = ecs->getComponent<cubz::graphics::Mesh>(entity);
            const auto& transform = ecs->getComponent<cubz::graphics::Transform>(entity);
            auto& meshRenderer = ecs->getComponent<MeshRenderer>(entity);

            meshRenderer.update(mesh, transform);
        }
    }

    void render(const cubz::graphics::Camera& camera) {
        for (const auto& entity : entities) {
            auto& meshRenderer = ecs->getComponent<MeshRenderer>(entity);
            meshRenderer.render(camera);
        }
    }
};

int main(int argc, char **argv) {
    utility::Log::addLogger(std::make_shared<utility::ConsoleLogger>());

    try {
        auto screen = cubz::graphics::opengl::Screen(1280, 800, "Physics Demo");
        screen.getContext().setMouseEnabled(false);

        auto ecs = cubz::graphics::ecs::EntityComponentSystem();
        ecs.initialize();

        // Register all components
        ecs.registerComponent<cubz::graphics::Transform>();
        ecs.registerComponent<cubz::graphics::RigidBody>();
        ecs.registerComponent<cubz::graphics::Gravity>();
        ecs.registerComponent<cubz::graphics::Mesh>();
        ecs.registerComponent<cubz::graphics::MeshRenderer>();

        // Create physics system
        auto physicsSystem = ecs.registerSystem<PhysicsSystem>();

        cubz::graphics::ecs::Signature physicsSignature;
        physicsSignature.set(ecs.getComponentType<cubz::graphics::Transform>());
        physicsSignature.set(ecs.getComponentType<cubz::graphics::RigidBody>());
        physicsSignature.set(ecs.getComponentType<cubz::graphics::Gravity>());
        ecs.setSystemSignature<PhysicsSystem>(physicsSignature);

        // Create render system
        auto renderSystem = ecs.registerSystem<RenderSystem>();

        cubz::graphics::ecs::Signature renderSignature;
        renderSignature.set(ecs.getComponentType<cubz::graphics::Mesh>());
        renderSignature.set(ecs.getComponentType<cubz::graphics::MeshRenderer>());
        renderSignature.set(ecs.getComponentType<cubz::graphics::Transform>());
        ecs.setSystemSignature<RenderSystem>(renderSignature);

        while (!screen.shouldQuit()) {
            screen.processInput();

            auto deltaTime = screen.getCamera().getDeltaTime();
            //physicsSystem->update(deltaTime);
            //renderSystem->update();
            //renderSystem->render(screen.getCamera());

            screen.clear();
            screen.render();
        }
    } catch (std::exception& e) {
        utility::Log::error(e);
    }
}