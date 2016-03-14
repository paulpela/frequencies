#version 430 core

layout (location = 0) in vec2 position;

layout (location = 20) uniform mat4 projectionMatrix;

void main() {
    gl_Position = projectionMatrix * vec4(position, 0.0, 1.0);    
}
