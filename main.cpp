#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "utility/Log.h"
#include "utility/ConsoleLogger.h"
#include "core/Screen.h"
#include "core/Chunk.h"
#include "core/ui/FreetypeContext.h"
#include "core/ui/FreetypeText.h"
#include "core/ResourceManager.h"
#include "core/ui/DebugView.h"
#include "core/GrassBlock.h"
#include "core/World.h"

using namespace std::string_literals;

int main() {
    utility::Log::addLogger(std::make_shared<utility::ConsoleLogger>());

    try {
        auto screen = core::opengl::Screen(800, 600, "Cubz - Experimental Version");
        screen.getCamera().setPosition({ -1.0f, 1.0f, -2.0f });

        auto world = core::World();
        world.setBlock(std::make_shared<core::GrassBlock>(), 1, 1, 0);

        auto fontCtx = core::ui::FreetypeContext();
        auto font = fontCtx.generateFont("Minecraftia_Regular.ttf", 24);

        auto debugView = core::ui::DebugView(font);

        while (!screen.shouldQuit()) {
            screen.clear();
            world.update();
            world.render(screen.getCamera());
            debugView.render(screen.getCamera());
            screen.render();
            screen.processInput();
        }
    } catch (std::exception &e) {
        utility::Log::error(e);
    }

    return 0;
}