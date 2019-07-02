#pragma once

#include "TextData.h"
#include "Camera.h"
#include "FreetypeCharMap.h"

namespace cubz::graphics::ui {
    class TextRenderer {
    public:
        void update(const TextData& text);
        void render(const Camera& camera, const FreetypeCharMap& charMap);

    private:
        TextData m_text;
    };
}