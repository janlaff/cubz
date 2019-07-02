#version 330 core

layout(location = 0) in vec3 vertexPosition;

out vec3 uv;

uniform mat4 viewProjection;

void main() {
    uv = vertexPosition;
    gl_Position = (viewProjection * vec4(vertexPosition, 1.0)).xyww; // Depth optimation
}