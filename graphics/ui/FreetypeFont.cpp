#include "FreetypeFont.h"

namespace graphics {
    FreetypeFont::FreetypeFont() {}

    void FreetypeFont::addCharacter(GLchar c, const FreetypeCharacter &character) {
        m_characters.emplace(c, character);
    }

    const FreetypeCharacter& FreetypeFont::getCharacter(GLchar c) const {
        return m_characters.at(c);
    }
}