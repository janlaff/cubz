#include "MeshRenderer.h"
#include "ResourceManager.h"
#include "Log.h"

#include <glm/gtc/matrix_transform.hpp>

namespace core {
    MeshRenderer::MeshRenderer()
        : m_shader(ResourceManager::getInstance().getShader("chunk"))
        , m_material {
            ResourceManager::getInstance().getTexture("terrain.png"),
            glm::vec3(1.0f),
            32
        } {
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

    MeshData& MeshRenderer::getMeshData() {
        return m_meshData;
    }

    void MeshRenderer::update() {
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

    void MeshRenderer::render(const Camera& camera, const glm::vec3& position) {
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

        auto model = glm::translate(glm::mat4(1.0f), position);

        m_shader.bind();
        m_shader.setMat4("mvp", camera.getModelViewProjection(model));
        m_shader.setMat4("model", model);
        //m_shader.setInt("disableLights", true);
        m_material.bind(m_shader);

        m_vertexArray.bind();
        m_elementBuffer.draw();
        m_vertexArray.unbind();

        m_material.unbind(m_shader);
        m_shader.unbind();

        glDisable(GL_DEPTH_TEST);
    }

    void MeshRenderer::updateLights(const WorldPosMap<opengl::PointLight> &lights) {
        m_shader.bind();
        auto i = 0;
        for (auto [pos, light] : lights) {
            light.bind(m_shader, i++);
        }
        m_shader.setInt("lightCount", i);
        m_shader.unbind();
    }
}