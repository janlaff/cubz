#pragma once

#include "FreetypeCharMap.h"

#include <string>
#include <map>

#include <ft2build.h>
#include FT_FREETYPE_H

namespace cubz::graphics::ui {
    class FreetypeContext {
    public:
        FreetypeContext(opengl::Shader shader);
        ~FreetypeContext();

        FreetypeCharMap generateCharMap(const std::string& name, int size);

    private:
        opengl::Shader m_shader;
        FT_Library m_library;
    };
}