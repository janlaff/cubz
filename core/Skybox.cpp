#include "Skybox.h"
#include "ResourceManager.h"
#include "opengl/VertexQuadBuilder.h"

#include <glm/gtc/matrix_transform.hpp>

namespace core {
    const float skyboxSize = 1.0f;

    Skybox::Skybox()
        : m_cubeMap("skybox")
        , m_shader(ResourceManager::getInstance().getShader("skybox")) {
        m_vertexArray.bind();
        m_vertexBuffer.bind();

        auto quadBuilder = opengl::VertexQuadBuilder();

        // North
        quadBuilder.addVertex({ -skyboxSize, skyboxSize, -skyboxSize });
        quadBuilder.addVertex({ skyboxSize, skyboxSize, -skyboxSize });
        quadBuilder.addVertex({ skyboxSize, -skyboxSize, -skyboxSize });
        quadBuilder.addVertex({ -skyboxSize, -skyboxSize, -skyboxSize });
        quadBuilder.addQuadVertices();

        // South
        quadBuilder.addVertex({ skyboxSize, skyboxSize, skyboxSize });
        quadBuilder.addVertex({ -skyboxSize, skyboxSize, skyboxSize });
        quadBuilder.addVertex({ -skyboxSize, -skyboxSize, skyboxSize });
        quadBuilder.addVertex({ skyboxSize, -skyboxSize, skyboxSize });
        quadBuilder.addQuadVertices();

        // East
        quadBuilder.addVertex({ skyboxSize, skyboxSize, -skyboxSize });
        quadBuilder.addVertex({ skyboxSize, skyboxSize, skyboxSize });
        quadBuilder.addVertex({ skyboxSize, -skyboxSize, skyboxSize });
        quadBuilder.addVertex({ skyboxSize, -skyboxSize, -skyboxSize });
        quadBuilder.addQuadVertices();

        // West
        quadBuilder.addVertex({ -skyboxSize, skyboxSize, skyboxSize });
        quadBuilder.addVertex({ -skyboxSize, skyboxSize, -skyboxSize });
        quadBuilder.addVertex({ -skyboxSize, -skyboxSize, -skyboxSize });
        quadBuilder.addVertex({ -skyboxSize, -skyboxSize, skyboxSize });
        quadBuilder.addQuadVertices();

        // Bottom
        quadBuilder.addVertex({ -skyboxSize, -skyboxSize, -skyboxSize });
        quadBuilder.addVertex({ skyboxSize, -skyboxSize, -skyboxSize });
        quadBuilder.addVertex({ skyboxSize, -skyboxSize, skyboxSize });
        quadBuilder.addVertex({ -skyboxSize, -skyboxSize, skyboxSize });
        quadBuilder.addQuadVertices();

        // Top
        quadBuilder.addVertex({ -skyboxSize, skyboxSize, skyboxSize });
        quadBuilder.addVertex({ skyboxSize, skyboxSize, skyboxSize });
        quadBuilder.addVertex({ skyboxSize, skyboxSize, -skyboxSize });
        quadBuilder.addVertex({ -skyboxSize, skyboxSize, -skyboxSize });
        quadBuilder.addQuadVertices();

        m_vertexBuffer.update(quadBuilder.getQuadVertices(), false);

        m_vertexBuffer.setAttribPointer();
        m_vertexArray.enableAttrib(0);
        m_vertexArray.unbind();
    }

    void Skybox::render(const core::Camera& camera, const glm::vec3& position, float ambient) {
        glDepthMask(GL_FALSE);

        m_vertexArray.bind();
        m_shader.bind();
        m_shader.setMat4("mvp", camera.getModelViewProjection(glm::translate(glm::mat4(1.0f), position)));
        m_shader.setFloat("ambient", ambient);
        m_cubeMap.bind();
        m_vertexBuffer.draw();
        m_cubeMap.unbind();
        m_shader.unbind();
        m_vertexArray.unbind();

        glDepthMask(GL_TRUE);
    }
}