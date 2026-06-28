#include "humangl.h"

Cube::Cube()
: _vertices{
    glm::vec3(-0.5f, -0.5f,  0.5f),
    glm::vec3( 0.5f, -0.5f,  0.5f),
    glm::vec3( 0.5f,  0.5f,  0.5f),
    glm::vec3(-0.5f,  0.5f,  0.5f),
    
    glm::vec3(-0.5f, -0.5f, -0.5f),
    glm::vec3( 0.5f, -0.5f, -0.5f),
    glm::vec3( 0.5f,  0.5f, -0.5f),
    glm::vec3(-0.5f,  0.5f, -0.5f)
  },

  _indices{
    0, 1, 2,  0, 2, 3,
    5, 4, 7,  5, 7, 6,
    4, 0, 3,  4, 3, 7,
    1, 5, 6,  1, 6, 2,
    3, 2, 6,  3, 6, 7,
    4, 5, 1,  4, 1, 0
  },

  _model(glm::mat4(1.0f)),
  _colour(glm::vec3(0)),
  
  _vao(0),
  _vbo(0)
{}


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
  GLint modelLocation = glGetUniformLocation(gShaderProgram, "uModel");
  glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(_model));

  GLint colourLocation = glGetUniformLocation(gShaderProgram, "uColour");
  glUniform4f(colourLocation, _colour.x, _colour.y, _colour.z, 1.0f);

  glBindVertexArray(_vao);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, _vertices.size());
}

void Cube::setColour(glm::vec3 colour) {
  _colour = colour;
}

void Cube::translate(glm::vec3 distance) {
  _model = glm::translate(_model, distance);
}

void Cube::rotate(GLfloat radians, glm::vec3 axis) {
  _model = glm::rotate(_model, radians, axis);
}

void Cube::scale(glm::vec3 factor) {
  _model = glm::scale(_model, factor);
}