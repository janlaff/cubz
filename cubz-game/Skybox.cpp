#include "Skybox.h"
#include "ResourceManager.h"
#include "opengl/VertexQuadBuilder.h"

#include <glm/gtc/matrix_transform.hpp>

namespace cubz::game {
    const float skyboxSize = 1.0f;

    Skybox::Skybox()
        : m_cubeMap("skybox")
        , m_shader(graphics::ResourceManager::getInstance().getShader("skybox")) {
        m_vertexArray.bind();
        m_vertexBuffer.bind();

        auto quadBuilder = graphics::opengl::VertexQuadBuilder();

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

    void Skybox::render(const graphics::Camera& camera, const glm::vec3& position, float ambient) {
        glDepthMask(GL_FALSE);
        glDepthFunc(GL_LEQUAL);
        glEnable(GL_DEPTH_TEST);

        m_vertexArray.bind();
        m_shader.bind();
        m_shader.setMat4("mvp", camera.getModelViewProjection(glm::translate(glm::mat4(1.0f), position)));
        m_shader.setFloat("ambient", ambient);
        m_cubeMap.bind();
        m_vertexBuffer.draw();
        m_cubeMap.unbind();
        m_shader.unbind();
        m_vertexArray.unbind();

        glDisable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        glDepthMask(GL_TRUE);
    }
}