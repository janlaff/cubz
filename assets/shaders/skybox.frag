#version 330 core

out vec3 color;
in vec3 uv;

uniform samplerCube skybox;

void main() {
    color = texture(skybox, uv).rgb;
}