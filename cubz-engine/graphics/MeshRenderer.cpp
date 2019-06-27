#include "MeshRenderer.h"
#include "ResourceManager.h"
#include "Log.h"

#include <glm/gtc/matrix_transform.hpp>

namespace cubz::graphics {
    MeshRenderer::MeshRenderer(cubz::graphics::opengl::Shader shader, cubz::graphics::opengl::Material material) {
        data = std::make_shared<Data>();

        data->shader = shader;
        data->material = material;
        data->vertexArray.bind();
        data->vertexBuffer.bind();
        data->vertexBuffer.setAttribPointer();
        data->uvBuffer.bind();
        data->uvBuffer.setAttribPointer();
        data->normalBuffer.bind();
        data->normalBuffer.setAttribPointer();
        data->vertexArray.enableAttrib(0);
        data->vertexArray.enableAttrib(1);
        data->vertexArray.enableAttrib(2);
        data->vertexArray.unbind();
    }

    void MeshRenderer::update(const Transform& transform, const Mesh& mesh) {
        data->vertexArray.bind();
        // Update vertices
        data->vertexBuffer.bind();
        data->vertexBuffer.update(mesh.vertices, false);
        data->vertexBuffer.setAttribPointer();
        // Update uvs
        data->uvBuffer.bind();
        data->uvBuffer.update(mesh.uvs);
        data->uvBuffer.setAttribPointer();
        // Update normals
        data->normalBuffer.bind();
        data->normalBuffer.update(mesh.normals, false);
        data->normalBuffer.setAttribPointer();
        // Update triangles
        data->elementBuffer.bind();
        data->elementBuffer.update(mesh.triangles);

        data->vertexArray.unbind();

        auto translation = glm::translate(glm::mat4(1.0f), transform.position);
        auto rotation = transform.rotation;
        auto scale = glm::scale(glm::mat4(1.f), transform.scale);

        data->model = translation * rotation * scale;
    }

    void MeshRenderer::render(const Camera& camera) {
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

        data->vertexArray.bind();
        data->shader.bind();
        //data->shader.setMat4("mvp", data->model);
        //data->shader.setMat4("mvp", camera.getModelViewProjection(data->model));
        data->shader.setMat4("mvp", camera.getModelViewProjection(glm::mat4(1.0f)));
        data->shader.setMat4("model", data->model);
        //data->shader.setInt("disableLights", true);
        data->material.bind(data->shader);
        data->elementBuffer.draw();
        data->material.unbind(data->shader);
        //data->shader.unbind();
        data->vertexArray.unbind();

        glDisable(GL_DEPTH_TEST);
    }

    /*void MeshRenderer::updateLights(const WorldPosMap<opengl::PointLight> &lights) {
        m_shader.bind();
        auto i = 0;
        for (auto [pos, light] : lights) {
            light.bind(m_shader, i++);
        }
        m_shader.setInt("lightCount", i);
        m_shader.unbind();
    }*/
}