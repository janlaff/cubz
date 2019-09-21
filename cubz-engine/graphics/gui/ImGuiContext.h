#pragma once

#include "../opengl/Context.h"

namespace cubz::graphics::gui {
    class ImGuiContext {
    public:
        ImGuiContext(opengl::Context& context);
        ~ImGuiContext();

        void newframe();
        void render();
    };
}