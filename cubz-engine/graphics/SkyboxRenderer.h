#pragma once

#include <memory>

#include "opengl/CubeMap.h"
#include "opengl/Shader.h"
#include "opengl/VertexArray.h"
#include "opengl/VertexBuffer.h"
#include "Camera.h"

namespace cubz::graphics {
    class SkyboxRenderer {
    public:
        struct Data {
            opengl::CubeMap cubeMap;
            opengl::Shader shader;
            opengl::VertexArray vertexArray;
            opengl::VertexBuffer vertexBuffer;
        };

        std::shared_ptr<Data> data;

        SkyboxRenderer() = default;
        SkyboxRenderer(opengl::CubeMap cubeMap, opengl::Shader shader);

        void render(const Camera& camera, const glm::vec3& playerPosition);
    };
}