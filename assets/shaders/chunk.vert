#version 330 core

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec2 vertexUv;
layout(location = 2) in vec3 vertexNormal;

uniform mat4 mvp;
uniform mat4 model;

out vec2 uv;
out vec3 normal;
out vec3 fragPos;

void main() {
    gl_Position = mvp * vec4(vertexPosition, 1.0);
    // Transform position to world space
    fragPos = vec3(model * vec4(vertexPosition, 1.0));
    uv = vertexUv;
    // Transform normal to world space
    normal = mat3(transpose(inverse(model))) * vertexNormal;
}