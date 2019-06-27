#include "FreetypeCharMap.h"

namespace cubz::graphics::ui {
    void FreetypeCharMap::addChar(char value, std::shared_ptr<FreetypeChar> fc) {
        m_chars[value] = fc;
    }

    bool FreetypeCharMap::hasChar(char value) const {
        return bool(m_chars[value]);
    }

    std::shared_ptr<FreetypeChar> FreetypeCharMap::getChar(char value) {
        return m_chars[value];
    }
}