#pragma once

#include "FreetypeCharMap.h"

#include <string>
#include <map>

#include <ft2build.h>
#include FT_FREETYPE_H

namespace core::ui {
    class FreetypeContext {
    public:
        FreetypeContext();
        ~FreetypeContext();

        FreetypeCharMap generateCharMap(const std::string& name, int size);

    private:
        FT_Library m_library;
    };
}