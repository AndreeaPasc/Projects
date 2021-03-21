#version 410 core

in vec3 fPosition;
in vec3 fNormal;
in vec2 fTexCoords;
in vec4 fPosEye;
in vec4 fragPosLightSpace;

out vec4 fColor;

//matrices
uniform mat4 model;
uniform mat4 view;
uniform mat3 normalMatrix;
//lighting
uniform vec3 lightDir;
uniform vec3 lightColor;
// textures
uniform sampler2D diffuseTexture;
uniform sampler2D specularTexture;
uniform sampler2D shadowMap;

//components
vec3 ambient;
float ambientStrength = 0.1f;
vec3 diffuse;
vec3 specular;
float specularStrength = 0.5f;

//Point light 
uniform vec3 pointLight;

float ambientPoint = 1.5f;
float specularStrengthPoint = 1.0f;
float shininessPoint = 32.0f;

vec3 computePointLight(vec4 lightPosEye, vec3 lightColor, float constant, float linear, float quadratic)
{	
	vec3 cameraPosEye = vec3(0.0f);	
	vec3 normalEye = normalize(normalMatrix * fNormal);	
	vec3 lightDirN = normalize(lightPosEye.xyz - fPosEye.xyz);	
	vec3 viewDirN = normalize(cameraPosEye - fPosEye.xyz);		
	vec3 ambient = ambientPoint * lightColor;	
	vec3 diffuse = max(dot(normalEye, lightDirN), 0.0f) * lightColor;	
	vec3 halfVector = normalize(lightDirN + viewDirN);	
	vec3 reflection = reflect(-lightDirN, normalEye);	
	float specCoeff = pow(max(dot(normalEye, halfVector), 0.0f), shininessPoint);	
	vec3 specular = specularStrengthPoint * specCoeff * lightColor;		
	float distance = length(lightPosEye.xyz - fPosEye.xyz);		
	float att = 1.0f / (constant + linear * distance + quadratic * distance * distance);		
	ambient *= vec3(texture(diffuseTexture, fTexCoords));	
	diffuse *= vec3(texture(diffuseTexture, fTexCoords));	
	specular *= vec3(texture(specularTexture, fTexCoords));		
	return (ambient + diffuse + specular) * att;
}

void computeDirLight()
{
    //compute eye space coordinates
    //vec4 fPosEye = view * model * vec4(fPosition, 1.0f);
    vec3 normalEye = normalize(normalMatrix * fNormal);

    //normalize light direction
    vec3 lightDirN = vec3(normalize(view * vec4(lightDir, 0.0f)));

    //compute view direction (in eye coordinates, the viewer is situated at the origin
    vec3 viewDir = normalize(- fPosEye.xyz);

    //compute ambient light
    ambient = ambientStrength * lightColor;

    //compute diffuse light
    diffuse = max(dot(normalEye, lightDirN), 0.0f) * lightColor;

    //compute specular light
    vec3 reflectDir = reflect(-lightDirN, normalEye);
    float specCoeff = pow(max(dot(viewDir, reflectDir), 0.0f), 32);
    specular = specularStrength * specCoeff * lightColor;
}

// fog
float computeFog()
{
	float fogDensity = 0.0009f;
	float fragmentDistance = length(fPosEye);
	float fogFactor = exp(-pow(fragmentDistance * fogDensity, 2));
	return clamp(fogFactor, 0.0f, 1.0f);
}

// shadow

float computeShadow(){

    vec3 normalizedCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    normalizedCoords = normalizedCoords * 0.5 + 0.5;
    float closestDepth = texture(shadowMap, normalizedCoords.xy).r;
    float currentDepth = normalizedCoords.z;
    //float bias = 0.0005f;
    float bias = max(0.05 * (1.0 - dot(fNormal, lightDir)), 0.0005);
    float shadow = currentDepth - bias > closestDepth ? 1.0 : 0.0;
    if (normalizedCoords.z > 1.0f)
        return 0.0f;

    shadow = 0.0;
    vec2 texelSize = 1.0 / textureSize(shadowMap, 0);
    for(int x = -1; x <= 1; ++x)
    {
        for(int y = -1; y <= 1; ++y)
        {
            float pcfDepth = texture(shadowMap, normalizedCoords.xy + vec2(x, y) * texelSize).r; 
            shadow += currentDepth - bias > pcfDepth ? 1.0 : 0.0;
        }
    }
    shadow /= 9.0;
    return shadow;
}

void main() 
{
    computeDirLight();

    ambient *= texture(diffuseTexture, fTexCoords).rgb;
    diffuse *= texture(diffuseTexture, fTexCoords).rgb;
    specular *= texture(specularTexture, fTexCoords).rgb;

    float shadowIntensity = 1.0f;
    float shadow = computeShadow() * shadowIntensity;

    vec3 pointColor = vec3(0.0f,0.0f,0.0f);

    pointColor = computePointLight(view * vec4(pointLight, 1.0f),vec3(1.0f, 0.4f, 0.0f), 1.0f, 0.022f, 0.0019f);
	vec3 color = min((ambient +(1.0f - shadow) * diffuse) +  (1.0f - shadow) * specular + pointColor, 1.0f);

    //compute final vertex color
    //vec3 color = min((ambient + diffuse) * texture(diffuseTexture, fTexCoords).rgb + specular * texture(specularTexture, fTexCoords).rgb + pointColor, 1.0f);

    //fColor = vec4(color, 1.0f);

    //fog
    float fogFactor = computeFog();
    vec3 fogColor = vec3(1.0f, 1.0f, 1.0f);	
    fColor = vec4(mix(fogColor, color, fogFactor), 1.0f);
}
