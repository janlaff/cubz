#include "TextGrid.h"

namespace core::ui {
    TextGrid::TextGrid(float lineHeight)
        : m_lineHeight(lineHeight)
        , m_numLines(0) {}

    static const float offset = 10.0f;

    glm::vec2 TextGrid::getTextPosition() {
        return {
            offset,
            800.0f - (m_numLines++ + 1) * (offset + m_lineHeight)
        };
    }
}