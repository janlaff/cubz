#version 330 core

// Used to render light different on different materials
struct Material {
    sampler2D texture;
    vec3 specular;
    float shininess;
};

struct Light {
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

out vec3 color;

in vec2 uv;
in vec3 normal;
in vec3 fragPos;

uniform vec3 playerPosition;
uniform Light light;
uniform Material material;

void main() {
    vec3 objectColor = texture2D(material.texture, uv).rgb;

    // Ambient lighting
    vec3 ambient = light.ambient * objectColor;
    // Diffuse lighting
    vec3 lightDir = normalize(light.position - fragPos);
    float diff = max(dot(normal, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * objectColor;

    // Specular lighting
    vec3 viewDir = normalize(playerPosition - fragPos);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * (spec * material.specular);

    // Combine all into the color
    color = ambient + diffuse + specular;
}