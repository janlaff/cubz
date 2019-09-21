cmake_minimum_required(VERSION 3.10)

find_package(imgui CONFIG REQUIRED)

set(
        GUI_SOURCE_FILES
        imgui_impl_glfw_gl3.cpp
        ImGuiContext.cpp
        ImGuiLogger.cpp
)

add_library(gui STATIC ${GUI_SOURCE_FILES})
target_compile_definitions(gui PUBLIC IMGUI_IMPL_OPENGL_LOADER_GLEW)
target_link_libraries(gui imgui::imgui)
