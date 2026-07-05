#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <glm/vec3.hpp>                         // glm::vec3
#include <glm/vec4.hpp>                         // glm::vec4
#include <glm/mat4x4.hpp>                       // glm::mat4
#include <glm/ext/matrix_transform.hpp>         // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp>        // glm::perspective
#include <glm/ext/scalar_constants.hpp>         // glm::pi
#include <glm/gtc/type_ptr.hpp>

#define SCREEN_HEIGHT   800
#define SCREEN_WIDTH    800

inline SDL_Window* gWindow = nullptr;
inline SDL_GLContext gGLContext = nullptr;

inline bool isRunning = true;
inline float g_offset = 0.0f;

inline GLuint gShaderProgram = 0;

// render.cpp
void initialize();
void loop();
void cleanup();

// shader.cpp
void vertexSpecification();
void createGraphicsPipeline();

// cube.cpp
class Cube {
	private:
    std::vector<GLfloat>	  _vertices;
    std::vector<GLuint>			_indices;
    glm::mat4               _model;
    glm::vec3               _colour;

		GLuint	_vao;
		GLuint	_vbo;
    GLuint  _ibo;
  
  public:
    Cube();
    
    void upload();
    void draw();

    void setColour(glm::vec3 colour);

    // Transformations follow the order: translate, rotate, scale
    void translate(glm::vec3 distance);
    void rotate(GLfloat radians, glm::vec3 axis);
    void scale(glm::vec3 factor);
};


// human.cpp
class Human {
  public:
    Cube head;
    Cube torso;

    Human();
    void upload();
    void draw();
};

inline Human human = Human();
