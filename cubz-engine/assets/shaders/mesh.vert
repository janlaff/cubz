#version 330 core

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec2 vertexUV;
layout(location = 2) in vec3 vertexNormal;

out vec2 uv;
out vec3 fragPos;
out vec3 normal;

uniform mat4 mvp;
uniform mat4 model;

void main() {
    gl_Position = mvp * vec4(vertexPosition, 1.0);
    uv = vertexUV;
    // Used for light calculations
    fragPos = vec3(model * vec4(vertexPosition, 1.0));
    // Transform normal to world space
    normal = mat3(transpose(inverse(model))) * vertexNormal;
}