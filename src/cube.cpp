#include "humangl.h"

Cube::Cube()
: _vertices{
    // front face
    -0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    
    // back face
    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f
  },

  _indices{
    // 2 triangles for each face
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
  // generate and bind Vertex Array Object (VAO)
  glGenVertexArrays(1, &_vao);
  glBindVertexArray(_vao);

  // Vertex Buffer Object (VBO) to store array of vertices
  glGenBuffers(1, &_vbo);
  glBindBuffer(GL_ARRAY_BUFFER, _vbo);
  glBufferData(
    GL_ARRAY_BUFFER,
    _vertices.size() * sizeof(GLfloat),
    _vertices.data(),
    GL_STATIC_DRAW
  );

  // Index Buffer Object (IBO) to store array of indicies
  glGenBuffers(1, &_ibo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo);
  glBufferData(
    GL_ELEMENT_ARRAY_BUFFER,
    _indices.size() * sizeof(GLuint),
    _indices.data(),
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
  glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
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