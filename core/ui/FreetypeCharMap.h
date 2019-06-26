#pragma once

#include <array>
#include <memory>

#include "FreetypeChar.h"

namespace core::ui {
    class FreetypeCharMap {
    public:
        void addChar(char value, std::shared_ptr<FreetypeChar> fc);
        bool hasChar(char value) const;
        std::shared_ptr<FreetypeChar> getChar(char value);

    private:
        std::array<std::shared_ptr<FreetypeChar>, 256> m_chars;
    };
}