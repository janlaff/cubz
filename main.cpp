#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "utility/Log.h"
#include "utility/ConsoleLogger.h"
#include "graphics/Screen.h"
#include "graphics/Model.h"
#include "graphics/FreetypeContext.h"
#include "graphics/FreetypeText.h"
#include "graphics/ShaderManager.h"

using namespace std::string_literals;

int main() {
    utility::Log::addLogger(std::make_shared<utility::ConsoleLogger>());

    try {
        auto screen = graphics::opengl::Screen(800, 600, "Cubz - Experimental Version");
        auto shaderManager = graphics::ShaderManager();
        auto model = graphics::Model(shaderManager.getShader("triangle"), "stone.bmp");
        auto fontCtx = graphics::FreetypeContext();
        auto font = fontCtx.generateFont("OpenSans-Regular.ttf", 48);
        auto fpsText = graphics::FreetypeText(font, shaderManager.getShader("text"));

        fpsText.setColor(glm::vec3(1.0f, 1.0f, 1.0f));
        fpsText.setPosition(10.0f, 10.0f);
        fpsText.setText("Fps should be displayed here");

        while (!screen.shouldQuit()) {
            screen.clear();
            model.render(screen.getCamera());
            fpsText.render(screen.getCamera());
            screen.render();
        }
    } catch (std::exception &e) {
        utility::Log::error(e);
    }

    return 0;
}