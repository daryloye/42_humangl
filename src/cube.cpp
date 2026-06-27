#include "humangl.h"

Cube::Cube(glm::vec3 center)
  : _center(center),
  _indices{
    0, 1, 2,  0, 2, 3,
    5, 4, 7,  5, 7, 6,
    4, 0, 3,  4, 3, 7,
    1, 5, 6,  1, 6, 2,
    3, 2, 6,  3, 6, 7,
    4, 5, 1,  4, 1, 0
  },
  _vao(0),
  _vbo(0)
{
  _vertices = {
    center + glm::vec3(-0.5f, -0.5f,  0.5f),
    center + glm::vec3( 0.5f, -0.5f,  0.5f),
    center + glm::vec3( 0.5f,  0.5f,  0.5f),
    center + glm::vec3(-0.5f,  0.5f,  0.5f),

    center + glm::vec3(-0.5f, -0.5f, -0.5f),
    center + glm::vec3( 0.5f, -0.5f, -0.5f),
    center + glm::vec3( 0.5f,  0.5f, -0.5f),
    center + glm::vec3(-0.5f,  0.5f, -0.5f)
  };
}


void Cube::upload() {
  // generate and bind vertex array object (VAO)
  glGenVertexArrays(1, &_vao);
  glBindVertexArray(_vao);

  // VBO for vertex positions
  glGenBuffers(1, &_vbo);
  glBindBuffer(GL_ARRAY_BUFFER, _vbo);
  glBufferData(
    GL_ARRAY_BUFFER,
    _vertices.size() * sizeof(glm::vec3),
    _vertices.data(),
    GL_STATIC_DRAW
  );

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
}


void Cube::draw() {
  glBindVertexArray(_vao);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 8);
}