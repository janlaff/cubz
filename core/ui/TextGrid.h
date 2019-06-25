#pragma once

#include "Screen.h"

namespace core::ui {
    class TextGrid {
    public:
        TextGrid(float lineHeight);

        glm::vec2 getTextPosition(int lines = 1);

    private:
        float m_width;
        float m_height;
        float m_lineHeight;
        float m_numLines;
    };
}