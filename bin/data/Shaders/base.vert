#version 150

in vec4 position;
in vec3 normal;
in vec2 texcoord;

out vec2 v_texcoord;
out vec3 v_normal;

uniform float size;
uniform float twistFactor;
uniform float waviness;

uniform mat4 viewMatrix;
uniform mat4 modelMatrix;
uniform mat4 projectionMatrix;
uniform mat4 modelViewProjectionMatrix;

mat4 rotationAroundY(float angle) {
    return mat4(cos(angle), 0.0, -sin(angle), 0.0,
                0.0,        1.0,  0.0,        0.0,
                sin(angle), 0.0,  cos(angle), 0.0,
                0.0,        0.0,  0.0,        1.0);
}

void main() {
    v_texcoord = texcoord;
    
    float rotationAngleY = position.y * twistFactor;
    vec4 pos = position * rotationAroundY(rotationAngleY);
    
    // In this app shading from the sun does not depend on where the camera is since we are using a directional light
    v_normal = (modelViewProjectionMatrix * vec4(normal, 0.0)).xyz;
    
    // Inflate the model
    vec4 worldSpacePos = modelMatrix * pos;
    worldSpacePos.xyz += normal * size;
    
    // Waviness
    worldSpacePos.x += sin(worldSpacePos.y / 50.0f) * waviness;
        
    gl_Position = projectionMatrix * viewMatrix * worldSpacePos;
}
