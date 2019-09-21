#pragma once

#include <imgui.h>
#include <vector>

#include "../../utility/Logger.h"

namespace cubz::graphics::gui {
    class ImGuiLogger : public utility::Logger {
    public:
        ImGuiLogger();

        void log(const utility::LogEntry& entry) override;
        void clear();
        void addLog(const char* fmt, ...) IM_FMTARGS(2);
        void render(const char* title, bool* p_open = NULL);

    private:
        ImGuiTextBuffer m_buf;
        ImGuiTextFilter m_filter;
        ImVector<int> m_lineOffsets;
        bool m_autoScroll;
    };
}