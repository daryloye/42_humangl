#version 410 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 colour;

uniform float u_offset;

out vec3 v_colour;

void main() {
  v_colour = colour;
  gl_Position = vec4(position.x, position.y + u_offset, position.z, 1.0);
}