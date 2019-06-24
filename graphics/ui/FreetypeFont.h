#pragma once

#include <map>

#include "opengl/Texture.h"

#include <ft2build.h>
#include FT_FREETYPE_H

#include <GL/glew.h>
#include <glm/glm.hpp>

namespace graphics::ui {
    struct FreetypeCharacter {
        opengl::Texture texture;
        GLuint advance;
        glm::ivec2 size;
        glm::ivec2 bearing;
    };

    class FreetypeFont {
    public:
        FreetypeFont();

        void addCharacter(GLchar c, const FreetypeCharacter& character);
        float getHeight() const;
        const FreetypeCharacter& getCharacter(GLchar c) const;

    private:
        std::map<GLchar, FreetypeCharacter> m_characters;
    };
}