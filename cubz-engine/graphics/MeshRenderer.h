#pragma once

#include <memory>

#include "PointLight.h"
#include "opengl/VertexBuffer.h"
#include "opengl/NormalBuffer.h"
#include "opengl/UVBuffer.h"
#include "opengl/VertexArray.h"
#include "opengl/ElementBuffer.h"
#include "opengl/Shader.h"
#include "opengl/Texture.h"
#include "opengl/Material.h"
#include "Mesh.h"
#include "Camera.h"
#include "BasicComponents.h"

namespace cubz::graphics {
    struct MeshRenderer {
        struct Data {
            opengl::VertexBuffer vertexBuffer;
            opengl::NormalBuffer normalBuffer;
            opengl::ElementBuffer elementBuffer;
            opengl::UVBuffer uvBuffer;
            opengl::VertexArray vertexArray;
            opengl::Shader shader;
            opengl::Material material;
            glm::mat4 model;
        };

        std::shared_ptr<Data> data;

        MeshRenderer() = default;
        MeshRenderer(opengl::Shader shader, opengl::Material material);

        void update(const Transform& transform, const Mesh& mesh);
        void render(const Camera& camera);
    };
}