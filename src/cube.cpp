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
  _transformModel(glm::mat4(1.0f)),
  _colour(glm::vec3(0.0f)),
  _position(glm::vec3(0.0f)),
  _rotation(glm::vec3(0.0f)),
  _scale(glm::vec3(1.0f)),
  
  _parent(nullptr),
  _anchorPoint(glm::vec3(0.0f)),

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


Cube& Cube::attachTo(Cube& parent, glm::vec3 anchorPoint, glm::vec3 direction) {
  _parent = &parent;

  // sets the anchor point relative to the parent cube
  _anchorPoint = anchorPoint * _parent->_scale;
  _position = 0.5f * direction * _scale;

  return *this;
}


Cube& Cube::setTranslation(glm::vec3 distance) {
  _position = distance;
  return *this;
}


Cube& Cube::translate(glm::vec3 distance) {
  _position += distance;
  return *this;
}


Cube& Cube::setRotation(glm::vec3 radians) {
  _rotation = radians;
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


Cube& Cube::updateModel() {
  if (_parent) {
    _transformModel = _parent->_transformModel;
  } else {
    _transformModel = glm::mat4(1.0f);
  }
  
  // Transformations follow the order: translate, rotate, scale
  _transformModel = glm::translate(_transformModel, _anchorPoint);
  
  _transformModel = glm::rotate(_transformModel, _rotation.x, glm::vec3(1, 0, 0));
  _transformModel = glm::rotate(_transformModel, _rotation.y, glm::vec3(0, 1, 0));
  _transformModel = glm::rotate(_transformModel, _rotation.z, glm::vec3(0, 0, 1));
  
  _transformModel = glm::translate(_transformModel, _position);
  
  // want to send translation and rotation to children, but not the scaling
  _model = glm::scale(_transformModel, _scale);  
  
  return *this;
}
