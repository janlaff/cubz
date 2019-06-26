#pragma once

#include <array>
#include <memory>

#include "FreetypeCharacter.h"

namespace core::ui {
    class FreetypeCharMap {
    public:
        void addChar(char value, std::shared_ptr<FreetypeCharacter> fc);
        bool hasChar(char value) const;
        std::shared_ptr<FreetypeCharacter> getChar(char value);

    private:
        std::array<std::shared_ptr<FreetypeCharacter>, 256> m_chars;
    };
}