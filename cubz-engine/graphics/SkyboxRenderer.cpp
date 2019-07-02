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
        auto skyboxSize = 1.0f;

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

    void SkyboxRenderer::render(const Camera &camera, const glm::vec3& playerPosition, float ambient) {
        glDepthMask(GL_FALSE);
        glDepthFunc(GL_LEQUAL);
        glEnable(GL_DEPTH_TEST);

        data->vertexArray.bind();
        data->shader.bind();
        // Remove position data
        auto view = glm::mat4(glm::mat3(camera.getView()));
        auto projection = camera.getProjection();
        data->shader.setMat4("viewProjection", projection * view);
        data->shader.setFloat("ambient", ambient);
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