#version 410 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 colour;

uniform float u_offset;
uniform mat4 u_model;

out vec3 v_colour;

void main() {
  v_colour = colour;
  gl_Position = u_model * vec4(position, 1.0);
}