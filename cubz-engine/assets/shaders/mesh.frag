#version 330 core

#define MAX_POINT_LIGHTS 128

struct Material {
    sampler2D texture;
    vec3 specular;
    float shininess;
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

struct DirectionalLight {
    vec3 direction;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    bool isActive;
};

in vec2 uv;
in vec3 normal;
in vec3 fragPos;

out vec4 color;

uniform Material material;
uniform DirectionalLight dirLight;
uniform PointLight pointLights[MAX_POINT_LIGHTS];
uniform int lightCount;
uniform vec3 playerPosition;
uniform bool disableLights;

vec4 calculatePointLight(PointLight light, vec3 normal, vec3 viewDir);
vec4 calculateDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDir);

void main() {
    vec3 norm = normalize(normal);
    vec3 viewDir = normalize(playerPosition - fragPos);
    vec4 result = vec4(0.0, 0.0, 0.0, 0.0);

    vec4 texColor = texture2D(material.texture, uv);

    if (texColor.a < 0.1) {
        discard;
    }

    if (disableLights) {
        color = texColor;
        return;
    }

    // Directional light
    if (dirLight.isActive) {
        result += calculateDirectionalLight(dirLight, norm, viewDir);
    }

    // Point Lights
    for (int i = 0; i < lightCount; ++i) {
        PointLight light = pointLights[i];

        if (light.isActive && length(light.position - fragPos) <= 32.0) {
            vec4 intensity = calculatePointLight(light, norm, viewDir);
            intensity.x = max(intensity.x, result.x);
            intensity.y = max(intensity.y, result.y);
            intensity.z = max(intensity.z, result.z);
            result = intensity;
        }
    }

    color = result;
}

vec4 calculatePointLight(PointLight light, vec3 normal, vec3 viewDir) {
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
    vec4 texColor = material.isActive ? texture2D(material.texture, uv) : vec4(0.5, 0.5, 0.0, 1.0);
    vec4 ambient = vec4(light.ambient, 1.0) * texColor;
    vec4 diffuse = vec4(light.diffuse * diff, 1.0) * texColor;
    vec4 specular = vec4(light.specular * spec, 1.0) * texColor;

    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;

    return ambient + diffuse + specular;
}

vec4 calculateDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDir) {
    vec3 lightDir = normalize(-light.direction);
    // Diffuse
    float diff = max(dot(normal, lightDir), 0.0);
    // Specular
    vec3 reflectDir = reflect(-lightDir, normal);
    float shininess = material.isActive ? material.shininess : 32;
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    // Combine all
    vec4 texColor = material.isActive ? texture2D(material.texture, uv) : vec4(0.5f, 0.5f, 0.0f, 1.0f);
    vec4 ambient = vec4(light.ambient, 1.0) * texColor;
    vec4 diffuse = vec4(light.diffuse * diff, 1.0) * texColor;
    vec4 specular = vec4(light.specular * spec, 1.0) * texColor;

    return ambient + diffuse + specular;
}