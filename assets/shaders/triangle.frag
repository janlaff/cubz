#version 330 core

out vec3 color;
in vec3 vertexColor;

void main() {
    color = vertexColor;
}