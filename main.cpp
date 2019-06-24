#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "utility/Log.h"
#include "utility/ConsoleLogger.h"
#include "core/Screen.h"
#include "core/Model.h"
#include "core/ui/FreetypeContext.h"
#include "core/ui/FreetypeText.h"
#include "core/ShaderManager.h"
#include "core/ui/DebugView.h"

using namespace std::string_literals;

int main() {
    utility::Log::addLogger(std::make_shared<utility::ConsoleLogger>());

    try {
        auto screen = core::opengl::Screen(800, 600, "Cubz - Experimental Version");
        auto model = core::Model(core::ShaderManager::getInstance().getShader("triangle"), "stone.bmp");

        auto fontCtx = core::ui::FreetypeContext();
        auto font = fontCtx.generateFont("Minecraftia_Regular.ttf", 24);

        auto debugView = core::ui::DebugView(font);

        while (!screen.shouldQuit()) {
            screen.clear();
            model.setPosition(glm::vec3(0, 0, 0));
            model.render(screen.getCamera());
            debugView.render(screen.getCamera());
            screen.render();
            screen.processInput();
        }
    } catch (std::exception &e) {
        utility::Log::error(e);
    }

    return 0;
}