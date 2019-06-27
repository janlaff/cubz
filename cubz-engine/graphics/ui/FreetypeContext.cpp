#include "FreetypeContext.h"

#include <stdexcept>

using namespace std::string_literals;

namespace cubz::graphics::ui {
    FreetypeContext::FreetypeContext(opengl::Shader shader) {
        if (FT_Init_FreeType(&m_library)) {
            throw std::runtime_error("Failed to initialize Freetype library");
        }
        m_shader = shader;
    }

    FreetypeContext::~FreetypeContext() {
        FT_Done_FreeType(m_library);
    }

    FreetypeCharMap FreetypeContext::generateCharMap(const std::string &name, int size) {
        FT_Face font;

        if (FT_New_Face(m_library, name.c_str(), 0, &font)) {
            throw std::runtime_error("Failed to load font " + name);
        }

        FT_Set_Pixel_Sizes(font, 0, size);

        auto result = FreetypeCharMap();

        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

        for (GLubyte c = 0; c < 128; ++c) {
            if (FT_Load_Char(font, c, FT_LOAD_RENDER)) {
                throw std::runtime_error("Failed to load glyph "s + (char) c);
            }

            GLuint texture;
            glGenTextures(1, &texture);
            glBindTexture(GL_TEXTURE_2D, texture);
            glTexImage2D(
                    GL_TEXTURE_2D,
                    0,
                    GL_RED,
                    font->glyph->bitmap.width,
                    font->glyph->bitmap.rows,
                    0,
                    GL_RED,
                    GL_UNSIGNED_BYTE,
                    font->glyph->bitmap.buffer
            );

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

            result.addChar(c, std::make_shared<FreetypeChar>(
                    opengl::Texture(texture, font->glyph->bitmap.width, font->glyph->bitmap.rows),
                    m_shader,
                    font->glyph->advance.x,
                    glm::ivec2(font->glyph->bitmap.width, font->glyph->bitmap.rows),
                    glm::ivec2(font->glyph->bitmap_left, font->glyph->bitmap_top)
            ));
        }

        FT_Done_Face(font);

        return result;
    }
}