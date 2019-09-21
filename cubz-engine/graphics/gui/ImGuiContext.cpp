#include "ImGuiContext.h"

#include <imgui.h>
#include "imgui_impl_glfw_gl3.h"

namespace cubz::graphics::gui {
    ImGuiContext::ImGuiContext(opengl::Context &context) {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui_ImplGlfwGL3_Init(context.getWindow(), true);
    }

    ImGuiContext::~ImGuiContext() {
        ImGui_ImplGlfwGL3_Shutdown();
    }

    void ImGuiContext::newframe() {
        ImGui_ImplGlfwGL3_NewFrame();
    }

    void ImGuiContext::render() {
        ImGui::Render();
    }
}