#include <glm/gtc/matrix_transform.hpp>
#include "FreetypeChar.h"
#include "ResourceManager.h"
#include "Mesh.h"
#include "opengl/VertexQuadBuilder.h"

namespace cubz::graphics::ui {
    FreetypeChar::FreetypeChar(cubz::graphics::opengl::Texture texture, opengl::Shader shader, GLuint advance, const glm::ivec2 &size,
                                         const glm::ivec2 &bearing)
                                         : m_texture(std::move(texture))
                                         , m_shader(shader)
                                         , m_advance(advance)
                                         , m_height(size.y) {
        m_vertexArray.bind();
        m_vertexBuffer.bind();

        auto xPos = bearing.x;
        auto yPos = -(size.y - bearing.y);
        auto width = size.x;
        auto height = size.y;

        auto quadBuilder = opengl::VertexQuadBuilder();
        quadBuilder.addVertex({ xPos, yPos + height, 0.0f });
        quadBuilder.addVertex({ xPos + width, yPos + height, 0.0f });
        quadBuilder.addVertex({ xPos + width, yPos, 0.0f });
        quadBuilder.addVertex({ xPos, yPos, 0.0f });
        quadBuilder.addQuadVertices();
        quadBuilder.addQuadUVs();

        m_vertexBuffer.update(quadBuilder.getQuadVertices(), false);
        m_vertexBuffer.setAttribPointer();
        m_uvBuffer.bind();
        m_uvBuffer.update(quadBuilder.getQuadUVs());
        m_uvBuffer.setAttribPointer();

        m_vertexArray.enableAttrib(0);
        m_vertexArray.enableAttrib(1);
        m_vertexArray.unbind();
    }

    void FreetypeChar::render(const cubz::graphics::Camera &camera, const glm::vec3& color, float x, float y) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        m_vertexArray.bind();
        m_shader.bind();

        auto textProjection = camera.getTextProjection();
        auto modelProjection = textProjection * glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0.0f));
        m_shader.setMat4("modelProjection", modelProjection);
        m_shader.setVec3("textColor", color);
        m_texture.bind();
        m_vertexBuffer.draw();
        m_texture.unbind();
        m_shader.unbind();
        m_vertexArray.unbind();

        glDisable(GL_BLEND);
    }

    GLuint FreetypeChar::getAdvance() const {
        return m_advance;
    }

    int FreetypeChar::getHeight() const {
        return m_height;
    }
}