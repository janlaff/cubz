#include <glm/gtc/matrix_transform.hpp>
#include "FreetypeText.h"
#include "ResourceManager.h"

namespace cubz::graphics::ui {
    FreetypeText::FreetypeText(FreetypeCharMap& charMap)
            : m_charMap(charMap)
            , m_x(0.0f)
            , m_y(0.0f)
            , m_color(0.0f, 0.0f, 0.0f) {}

    float FreetypeText::getWidth() const {
        auto width = 0.0f;

        for (auto c : m_text) {
            width += m_charMap.getChar(c)->getAdvance() >> 6;
        }

        return width;
    }

    void FreetypeText::setPosition(const glm::vec2& position) {
        m_x = position.x;
        m_y = position.y;
    }

    void FreetypeText::setColor(const glm::vec3& color) {
        m_color = color;
    }

    void FreetypeText::setText(const std::string &text) {
        m_text = text;
    }

    void FreetypeText::update() {
        m_textBuffer = m_text;
    }

    void FreetypeText::render(const Camera &camera) {
        float x = m_x;
        float y = m_y;

        for (char c : m_textBuffer) {
            auto ch = m_charMap.getChar(c);

            if (c == '\n') {
                x = m_x;
                y -= ch->getHeight() + 10.0f;
                continue;
            }

            ch->render(camera, m_color, x, y);
            x += ch->getAdvance() >> 6;
        }
    }
}