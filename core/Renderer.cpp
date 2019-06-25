#include "Renderer.h"
#include "ResourceManager.h"
#include "Log.h"

#include <glm/gtc/matrix_transform.hpp>

namespace core {
    Renderer::Renderer()
        : m_texture(ResourceManager::getInstance().getTexture("terrain.png"))
        , m_shader(ResourceManager::getInstance().getShader("chunk")) {
        m_vertexArray.bind();
        m_vertexBuffer.bind();
        m_vertexBuffer.setAttribPointer();
        m_uvBuffer.bind();
        m_uvBuffer.setAttribPointer();
        m_normalBuffer.bind();
        m_normalBuffer.setAttribPointer();
        m_vertexArray.enableAttrib(0);
        m_vertexArray.enableAttrib(1);
        m_vertexArray.enableAttrib(2);
        m_vertexArray.unbind();
    }

    MeshData& Renderer::getMeshData() {
        return m_meshData;
    }

    void Renderer::update() {
        if (m_meshData.normals.size() != m_meshData.vertices.size()) {
            utility::Log::warning("Incorrect normals");
        }

        m_vertexArray.bind();
        // Update vertices
        m_vertexBuffer.bind();
        m_vertexBuffer.update(m_meshData.vertices, false);
        m_vertexBuffer.setAttribPointer();
        // Update normals
        m_normalBuffer.bind();
        m_normalBuffer.update(m_meshData.normals, false);
        m_normalBuffer.setAttribPointer();
        // Update triangles
        m_elementBuffer.bind();
        m_elementBuffer.update(m_meshData.triangles);
        // Update uvs
        m_uvBuffer.bind();
        m_uvBuffer.update(m_meshData.uvs);
        m_uvBuffer.setAttribPointer();

        m_vertexArray.unbind();
    }

    void Renderer::render(const Camera& camera, const glm::vec3& position) {
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

        auto model = glm::translate(glm::mat4(1.0f), position);

        m_shader.bind();
        m_shader.setMat4("mvp", camera.getModelViewProjection(model));
        m_shader.setMat4("model", model);
        m_shader.setInt("material.texture", 0);
        glActiveTexture(GL_TEXTURE0);
        m_texture.bind();

        m_vertexArray.bind();
        m_elementBuffer.draw();
        m_vertexArray.unbind();

        m_texture.unbind();
        m_shader.unbind();

        glDisable(GL_DEPTH_TEST);
    }
}