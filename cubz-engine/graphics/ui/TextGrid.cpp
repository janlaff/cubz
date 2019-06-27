#include "TextGrid.h"

namespace cubz::graphics::ui {
    TextGrid::TextGrid(float lineHeight)
        : m_lineHeight(lineHeight)
        , m_numLines(0) {}

    static const float offset = 10.0f;

    glm::vec2 TextGrid::getTextPosition(int lines) {
        auto tmp = m_numLines;
        m_numLines += lines;
        return {
            offset,
            800.0f - (tmp + 1) * (offset + m_lineHeight)
        };
    }
}