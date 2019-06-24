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

using namespace std::string_literals;

int main() {
    utility::Log::addLogger(std::make_shared<utility::ConsoleLogger>());

    try {
        auto screen = core::opengl::Screen(800, 600, "Cubz - Experimental Version");
        //auto chunk = core::Chunk(glm::vec3(0, 0, 0));

        auto chunkRenderer = core::ChunkRenderer();
        auto chunk = core::Chunk(glm::vec3(0, 0, 0));
        auto blockA = core::GrassBlock();

        for (int x = 0; x < 16; ++x) {
            for (int z = 0; z < 16; ++z) {
                blockA.addToMesh(chunk, x, 0, z, chunkRenderer.getMeshData());
            }
        }

        chunkRenderer.update();

        auto fontCtx = core::ui::FreetypeContext();
        auto font = fontCtx.generateFont("Minecraftia_Regular.ttf", 24);

        auto debugView = core::ui::DebugView(font);

        while (!screen.shouldQuit()) {
            screen.clear();
            //chunk.render(screen.getCamera());
            chunkRenderer.render(screen.getCamera(), glm::vec3(0, 0, 0));
            debugView.render(screen.getCamera());
            screen.render();
            screen.processInput();
        }
    } catch (std::exception &e) {
        utility::Log::error(e);
    }

    return 0;
}