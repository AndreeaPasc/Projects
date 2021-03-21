#version 410 core

in vec3 textureCoordinates;
out vec4 color;

uniform samplerCube skybox;
vec3 viewDirection;
vec3 normal;

void main()
{
    // vec4(0.5f, 0.5f, 0.5f, 1.0f)
    color = texture(skybox, textureCoordinates);
    vec3 viewDirectionN = normalize(viewDirection);
    vec3 normalN = normalize(normal);
    vec3 reflection = reflect(viewDirectionN, normalN);
    vec3 colorFromSkybox = vec3(texture(skybox, reflection));

}
