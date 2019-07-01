#include <glm/gtc/matrix_transform.hpp>
#include "SkyboxRenderer.h"
#include "opengl/VertexQuadBuilder.h"

namespace cubz::graphics {
    SkyboxRenderer::SkyboxRenderer(opengl::CubeMap cubeMap, opengl::Shader shader) {
        data = std::make_shared<Data>();

        data->cubeMap = cubeMap;
        data->shader = shader;

        data->vertexArray.bind();
        data->vertexBuffer.bind();

        auto quadBuilder = opengl::VertexQuadBuilder();
        auto skyboxSize = 10.0f;

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

        data->vertexBuffer.update(quadBuilder.getQuadVertices(), false);

        data->vertexBuffer.setAttribPointer();
        data->vertexArray.enableAttrib(0);
        data->vertexArray.unbind();
    }

    void SkyboxRenderer::render(const Camera &camera, const glm::vec3& playerPosition) {
        glDepthMask(GL_FALSE);
        glDepthFunc(GL_LEQUAL);
        glEnable(GL_DEPTH_TEST);

        data->vertexArray.bind();
        data->shader.bind();
        data->shader.setMat4("mvp", camera.getModelViewProjection(glm::translate(glm::mat4(1.0f), playerPosition)));
        data->shader.setFloat("ambient", 1.0f);
        data->cubeMap.bind();
        data->vertexBuffer.draw();
        data->cubeMap.unbind();
        data->shader.unbind();
        data->vertexArray.unbind();

        glDisable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        glDepthMask(GL_TRUE);
    }
}