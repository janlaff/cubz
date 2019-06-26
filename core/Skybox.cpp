#include "Skybox.h"
#include "ResourceManager.h"
#include "opengl/VertexQuadBuilder.h"

#include <glm/gtc/matrix_transform.hpp>

namespace core {
    Skybox::Skybox(float scale)
        : m_cubeMap("skybox")
        , m_shader(ResourceManager::getInstance().getShader("skybox")) {
        m_vertexArray.bind();
        m_vertexBuffer.bind();

        auto quadBuilder = opengl::VertexQuadBuilder();

        // North
        quadBuilder.addVertex({ -scale, scale, -scale });
        quadBuilder.addVertex({ scale, scale, -scale });
        quadBuilder.addVertex({ scale, -scale, -scale });
        quadBuilder.addVertex({ -scale, -scale, -scale });
        quadBuilder.addQuadVertices();

        // South
        quadBuilder.addVertex({ scale, scale, scale });
        quadBuilder.addVertex({ -scale, scale, scale });
        quadBuilder.addVertex({ -scale, -scale, scale });
        quadBuilder.addVertex({ scale, -scale, scale });
        quadBuilder.addQuadVertices();

        // East
        quadBuilder.addVertex({ scale, scale, -scale });
        quadBuilder.addVertex({ scale, scale, scale });
        quadBuilder.addVertex({ scale, -scale, scale });
        quadBuilder.addVertex({ scale, -scale, -scale });
        quadBuilder.addQuadVertices();

        // West
        quadBuilder.addVertex({ -scale, scale, scale });
        quadBuilder.addVertex({ -scale, scale, -scale });
        quadBuilder.addVertex({ -scale, -scale, -scale });
        quadBuilder.addVertex({ -scale, -scale, scale });
        quadBuilder.addQuadVertices();

        // Bottom
        quadBuilder.addVertex({ -scale, -scale, -scale });
        quadBuilder.addVertex({ scale, -scale, -scale });
        quadBuilder.addVertex({ scale, -scale, scale });
        quadBuilder.addVertex({ -scale, -scale, scale });
        quadBuilder.addQuadVertices();

        // Top
        quadBuilder.addVertex({ -scale, scale, scale });
        quadBuilder.addVertex({ scale, scale, scale });
        quadBuilder.addVertex({ scale, scale, -scale });
        quadBuilder.addVertex({ -scale, scale, -scale });
        quadBuilder.addQuadVertices();

        m_vertexBuffer.update(quadBuilder.getQuadVertices(), false);

        m_vertexBuffer.setAttribPointer();
        m_vertexArray.enableAttrib(0);
        m_vertexArray.unbind();
    }

    void Skybox::render(const core::Camera& camera) {
        glDepthMask(GL_FALSE);

        m_vertexArray.bind();
        m_shader.bind();
        m_shader.setMat4("mvp", camera.getModelViewProjection(glm::translate(glm::mat4(1.0f), m_position)));
        m_cubeMap.bind();
        m_vertexBuffer.draw();
        m_cubeMap.unbind();
        m_shader.unbind();
        m_vertexArray.unbind();

        glDepthMask(GL_TRUE);
    }

    void Skybox::setPosition(const glm::vec3 &position) {
        m_position = position;
    }
}