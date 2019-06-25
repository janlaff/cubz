#version 330 core

out vec3 color;

in vec2 uv;
in vec3 normal;
in vec3 fragPos;

uniform sampler2D texture;
uniform vec3 lightPosition;
uniform vec3 playerPosition;

void main() {
    vec3 objectColor = texture2D(texture, uv).rgb;

    // Ambient lighting
    float ambientStrength = 0.1;
    vec3 lightColor = vec3(1.0, 1.0, 1.0);
    vec3 ambient = ambientStrength * lightColor;

    // Diffuse lighting
    vec3 lightDir = normalize(lightPosition - fragPos);
    float diff = max(dot(normal, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    // Specular lighting
    float specularStrength = 0.5;
    vec3 viewDir = normalize(playerPosition - fragPos);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

    // Combine all into the color
    color = (ambient + diffuse + specular) * objectColor;
}