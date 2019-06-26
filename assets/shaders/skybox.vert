#version 330 core

layout(location = 0) in vec3 vertexPosition;

out vec3 uv;

uniform mat4 mvp;

void main() {
    uv = vertexPosition;
    gl_Position = mvp * vec4(vertexPosition, 1.0);
}