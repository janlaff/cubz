#include "FreetypeFont.h"

namespace graphics::ui {
    FreetypeFont::FreetypeFont() {}

    void FreetypeFont::addCharacter(GLchar c, const FreetypeCharacter &character) {
        m_characters.emplace(c, character);
    }

    float FreetypeFont::getHeight() const {
        return getCharacter('B').size.y;
    }

    const FreetypeCharacter& FreetypeFont::getCharacter(GLchar c) const {
        return m_characters.at(c);
    }
}