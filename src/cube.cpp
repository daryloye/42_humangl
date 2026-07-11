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

  _model(glm::mat4(0)),
  _colour(glm::vec3(0)),
  _position(glm::vec3(0)),
  _rotation(glm::vec3(0)),
  _scale(glm::vec3(1)),
  _anchorPoint(glm::vec3(0)),

  _vao(0),
  _vbo(0),
  _ibo(0)
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
  glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);
}


Cube& Cube::setColour(glm::vec3 colour) {
  _colour = colour;
  return *this;
}

Cube& Cube::translate(glm::vec3 distance) {
  _position += distance;
  return *this;
}

Cube& Cube::rotate(glm::vec3 radians) {
  _rotation += radians;
  return *this;
}

Cube& Cube::scale(glm::vec3 factor) {
  _scale *= factor;
  return *this;
}


glm::mat4 Cube::updateModel(glm::mat4 transformModel) {

  glm::vec4 anchorPoint = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
  glm::vec4 localOffset = glm::vec4(0.0f, 0.125f, 0.0f, 0.0f);

  glm::vec4 vectorRight   = glm::normalize(transformModel * glm::vec4(1, 0, 0, 0));
  glm::vec4 vectorUp      = glm::normalize(transformModel * glm::vec4(0, 1, 0, 0));
  glm::vec4 vectorForward = glm::normalize(transformModel * glm::vec4(0, 0, 1, 0));

  glm::vec3 worldPosition = glm::vec3(
    transformModel      * anchorPoint
    + vectorRight   * _position.x
    + vectorUp      * _position.y
    + vectorForward * _position.z
  );

  // Transformations follow the order: translate, rotate, scale
  // _model = glm::translate(_model, _position);
  transformModel = glm::translate(transformModel, worldPosition);

  transformModel = glm::rotate(transformModel, _rotation.x, glm::vec3(1, 0, 0));
  transformModel = glm::rotate(transformModel, _rotation.y, glm::vec3(0, 1, 0));
  transformModel = glm::rotate(transformModel, _rotation.z, glm::vec3(0, 0, 1));

  _model = glm::scale(transformModel, _scale);  // want to send translation and rotation to children, but not the scaling
  
  return transformModel;
}


void Cube::print() {
  std::cout << glm::to_string(_position) << std::endl;
  // std::cout << "scale x: " << glm::length(glm::vec3(_model[0])) << std::endl;
  // std::cout << "scale y: " << glm::length(glm::vec3(_model[1])) << std::endl;
  // std::cout << "scale z: " << glm::length(glm::vec3(_model[2])) << std::endl;
}