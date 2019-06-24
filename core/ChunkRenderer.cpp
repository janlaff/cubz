#include "ChunkRenderer.h"
#include "ResourceManager.h"

#include <glm/gtc/matrix_transform.hpp>

namespace core {
    ChunkRenderer::ChunkRenderer()
        : m_texture(ResourceManager::getInstance().getTexture("tiles.png"))
        , m_shader(ResourceManager::getInstance().getShader("chunk")) {
        m_vertexArray.bind();
        m_vertexBuffer.bind();
        m_vertexBuffer.setAttribPointer();
        m_uvBuffer.bind();
        m_uvBuffer.setAttribPointer();
        m_elementBuffer.bind();
        m_elementBuffer.setAttribPointer();
        m_vertexArray.enableAttrib(0);
        m_vertexArray.enableAttrib(1);
        m_vertexArray.unbind();
    }

    MeshData& ChunkRenderer::getMeshData() {
        return m_meshData;
    }

    void ChunkRenderer::update() {
        m_vertexArray.bind();
        // Update vertices
        m_vertexBuffer.bind();
        m_vertexBuffer.update(m_meshData.vertices, false);
        m_vertexBuffer.setAttribPointer();
        // Update triangles
        m_elementBuffer.bind();
        m_elementBuffer.update(m_meshData.triangles);
        m_elementBuffer.setAttribPointer();
        // Update uvs
        m_uvBuffer.bind();
        m_uvBuffer.update(m_meshData.uvs);
        m_uvBuffer.setAttribPointer();

        m_vertexArray.unbind();
    }

    void ChunkRenderer::render(const Camera& camera, const glm::vec3& position) {
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

        m_shader.bind();
        m_shader.setMat4("mvp", camera.getModelViewProjection(glm::translate(glm::mat4(1.0f), position)));
        m_texture.bind();

        m_vertexArray.bind();
        m_elementBuffer.draw();
        m_vertexArray.unbind();

        m_texture.unbind();
        m_shader.unbind();

        glDisable(GL_DEPTH_TEST);
    }
}