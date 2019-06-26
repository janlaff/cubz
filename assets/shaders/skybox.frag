#version 330 core

out vec3 color;
in vec3 uv;

uniform samplerCube skybox;
uniform float ambient;

void main() {
    color = texture(skybox, uv).rgb * vec3(ambient);
}