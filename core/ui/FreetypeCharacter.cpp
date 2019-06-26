#include <glm/gtc/matrix_transform.hpp>
#include "FreetypeCharacter.h"
#include "ResourceManager.h"
#include "MeshData.h"
#include "opengl/VertexQuadBuilder.h"

namespace core::ui {
    FreetypeCharacter::FreetypeCharacter(core::opengl::Texture texture, GLuint advance, const glm::ivec2 &size,
                                         const glm::ivec2 &bearing)
                                         : m_texture(std::move(texture))
                                         , m_advance(advance)
                                         , m_height(size.y)
                                         , m_shader(ResourceManager::getInstance().getShader("text")){
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

    void FreetypeCharacter::render(const core::Camera &camera, const glm::vec3& color, float x, float y) {
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

    GLuint FreetypeCharacter::getAdvance() const {
        return m_advance;
    }

    int FreetypeCharacter::getHeight() const {
        return m_height;
    }
}