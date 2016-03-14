#version 430 core

uniform sampler2D t;

out vec4 color;

void main() {
    color = texture(t, gl_FragCoord.xy);
}
