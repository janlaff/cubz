#version 330 core

struct Material {
    sampler2D texture;
    vec3 specular;
    float shininess;
    bool isActive;
};

in vec2 uv;
out vec4 color;

uniform Material material;

void main() {
    color = texture2D(material.texture, uv);
}