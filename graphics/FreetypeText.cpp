#include "FreetypeText.h"

namespace graphics {
    FreetypeText::FreetypeText(const FreetypeFont &font, opengl::Shader shader)
            : m_font(font), m_x(0.0f), m_y(0.0f), m_color(1.0f, 1.0f, 1.0f), m_shader(shader), m_scale(1.0f), m_text("löl") {
        m_vertexArray.bind();
        m_vertexBuffer.bind();
        m_vertexBuffer.update(std::vector<glm::vec3>(4), true);

        m_elementBuffer.bind();
        m_elementBuffer.update({
            0, 2, 3,
            0, 1, 2
        });

        m_uvBuffer.bind();
        m_uvBuffer.update({
            { 0.0f, 0.0f },
            { 1.0f, 0.0f },
            { 1.0f, 1.0f },
            { 0.0f, 1.0f }
        });

        m_vertexBuffer.unbind();
        m_elementBuffer.unbind();
        m_uvBuffer.unbind();
    }

    void FreetypeText::setPosition(float x, float y) {
        m_x = x;
        m_y = y;
    }

    void FreetypeText::setColor(glm::vec3 color) {
        m_color = color;
    }

    void FreetypeText::setText(const std::string &text) {
        m_text = text;
    }

    void FreetypeText::setScale(float scale) {
        m_scale = scale;
    }

    void FreetypeText::render(const Camera &camera) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        m_shader.bind();
        m_shader.setVec3("textColor", m_color);
        m_shader.setMat4("projection", camera.getTextProjection());
        m_shader.enableVertexAttribArray(0);
        m_shader.enableVertexAttribArray(1);

        float x = m_x;

        for (auto c : m_text) {
            auto ch = m_font.getCharacter(c);

            auto xPos = x + ch.bearing.x * m_scale;
            auto yPos = m_y - (ch.size.y - ch.bearing.y) * m_scale;
            auto width = ch.size.x * m_scale;
            auto height = ch.size.y * m_scale;

            auto vertices = std::vector<glm::vec3> {
                    { xPos, yPos + height, 0.0f },
                    { xPos + width, yPos + height, 0.0f },
                    { xPos + width, yPos, 0.0f },
                    { xPos, yPos, 0.0f },
            };

            ch.texture.bind();

            m_vertexArray.bind();

            m_vertexBuffer.bind();
            m_vertexBuffer.update(vertices, true);
            m_uvBuffer.bind();
            m_elementBuffer.bind();
            m_elementBuffer.draw();

            m_uvBuffer.unbind();
            m_vertexBuffer.unbind();
            m_elementBuffer.unbind();

            m_vertexArray.unbind();

            ch.texture.unbind();

            x += (ch.advance >> 6) * m_scale;
        }

        m_shader.disableVertexAttribArray(0);
        m_shader.disableVertexAttribArray(1);
        m_shader.unbind();

        glDisable(GL_BLEND);
    }
}