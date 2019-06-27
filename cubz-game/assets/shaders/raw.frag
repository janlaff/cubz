#version 330 core

out vec3 color;

uniform vec3 objectColor;

void main() {
    color = objectColor;
}