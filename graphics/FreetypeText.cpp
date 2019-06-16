#include "FreetypeText.h"

namespace graphics {
    FreetypeText::FreetypeText(const FreetypeFont &font, opengl::Shader shader)
            : m_font(font), m_x(0.0f), m_y(0.0f), m_color(1.0f, 1.0f, 1.0f), m_shader(shader) {
        m_vertexArray.bind();
        m_vertexBuffer.bind();
        //m_vertexBuffer.update(std::vector<glm::vec3>())
    }

    void FreetypeText::setPosition(float x, float y) {
        m_x = x;
        m_y = y;
    }

    void FreetypeText::setColor(glm::vec3 color) {
        m_color = color;
    }

    void FreetypeText::setText(const std::string &text) {
        for (auto c : text) {

        }
    }

    void FreetypeText::render(const Camera &camera) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        m_shader.bind();
        m_shader.unbind();
        glDisable(GL_BLEND);
    }
}