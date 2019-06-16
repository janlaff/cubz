#pragma once

#include "FreetypeFont.h"

#include <string>
#include <map>

#include <ft2build.h>
#include FT_FREETYPE_H

namespace graphics {
    class FreetypeContext {
    public:
        FreetypeContext();
        ~FreetypeContext();

        FreetypeFont generateFont(const std::string& name, int size);

    private:
        FT_Library m_library;
    };
}