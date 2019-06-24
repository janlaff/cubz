#version 330 core

out vec3 color;
in vec2 uv;

uniform sampler2D texture;

void main() {
    color = texture2D(texture, uv).rgb;
}