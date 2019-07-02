#include "TextRenderer.h"

namespace cubz::graphics::ui {
    void TextRenderer::update(const TextData& text) {
        m_text = text;
    }

    void TextRenderer::render(const Camera &camera, const FreetypeCharMap& charMap) {
        auto position = m_text.position;

        for (auto c : m_text.value) {
            auto ch = charMap.getChar(c);

            if (c == '\n') {
                position.x = m_text.position.x;
                position.y -= ch->getHeight() + 10.0f;
                continue;
            }

            ch->render(camera, m_text.color, position.x, position.y);
            position.x += ch->getAdvance() >> 6;
        }
    }
}