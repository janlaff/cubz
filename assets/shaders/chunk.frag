#version 330 core

// Used to render light different on different materials
struct Material {
    sampler2D texture;
    vec3 specular;
    float shininess;
    bool isActive;
};

struct DirectionalLight {
    vec3 direction;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    bool isActive;
};

struct PointLight {
    vec3 position;
    float constant;
    float linear;
    float qudratic;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    bool isActive;
};

#define MAX_POINT_LIGHTS 128

uniform PointLight pointLights[MAX_POINT_LIGHTS];
uniform DirectionalLight dirLight;

out vec3 color;

in vec2 uv;
in vec3 normal;
in vec3 fragPos;

uniform vec3 playerPosition;
uniform Material material;

vec3 calculatePointLight(PointLight light, vec3 normal, vec3 viewDir);
vec3 calculateDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDir);

void main() {
    vec3 viewDir = normalize(playerPosition - fragPos);
    vec3 result = vec3(0.0, 0.0, 0.0);
    // Directional light
    if (dirLight.isActive) {
        result += calculateDirectionalLight(dirLight, normal, viewDir);
    }
    // Point Lights
    for (int i = 0; i < MAX_POINT_LIGHTS; ++i) {
        PointLight light = pointLights[i];

        if (light.isActive) {
            result += calculatePointLight(light, normal, viewDir);
        }
    }

    color = result;
}

vec3 calculatePointLight(PointLight light, vec3 normal, vec3 viewDir) {
    vec3 lightDir = normalize(light.position - fragPos);
    // Diffuse
    float diff = max(dot(normal, lightDir), 0.0);
    // Specular
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // Attenuation
    float distance = length(light.position - fragPos);
    float constant = light.constant;
    float linear = light.linear * distance;
    float qudratic = light.qudratic * (distance * distance);
    float attenuation = 1.0 / (constant + linear + qudratic);
    // Combine all
    vec3 texColor = material.isActive ? texture2D(material.texture, uv).rgb : vec3(0.5f, 0.5f, 0.0f);
    vec3 ambient = light.ambient * texColor;
    vec3 diffuse = light.diffuse * diff * texColor;
    vec3 specular = light.specular * spec * texColor;

    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;

    return ambient + diffuse + specular;
}

vec3 calculateDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDir) {
    vec3 lightDir = normalize(-light.direction);
    // Diffuse
    float diff = max(dot(normal, lightDir), 0.0);
    // Specular
    vec3 reflectDir = reflect(-lightDir, normal);
    float shininess = material.isActive ? material.shininess : 32;
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    // Combine all
    vec3 texColor = material.isActive ? texture2D(material.texture, uv).rgb : vec3(0.5f, 0.5f, 0.0f);
    vec3 ambient = light.ambient * texColor;
    vec3 diffuse = light.diffuse * diff * texColor;
    vec3 specular = light.specular * spec * texColor;

    return ambient + diffuse + specular;
}