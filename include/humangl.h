#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <cmath>

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

#define LIMB_BASE_ROTATION  glm::vec3(0.25f, 0.0f, 0.0f)

inline SDL_Window* gWindow = nullptr;
inline SDL_GLContext gGLContext = nullptr;

inline GLuint gShaderProgram = 0;

inline bool isRunning = true;

// render.cpp
void initialize();
void loop();
void cleanup();

// shader.cpp
void createGraphicsPipeline();

enum class Movement {
  None,
  Jump,
  Walk
};

// cube.cpp
class Cube {
	private:
    std::vector<GLfloat>	  _vertices;
    std::vector<GLuint>			_indices;
    
    glm::mat4   _model;
    glm::mat4   _transformModel;    // used to send translation and rotation to children, but not scaling
    glm::vec3   _colour;
    glm::vec3   _position;
    glm::vec3   _rotation;
    glm::vec3   _scale;
    
    Cube*       _parent;
    glm::vec3   _anchorPoint;
    
		GLuint	_vao;
		GLuint	_vbo;
    GLuint  _ibo;
    
  public:
    Cube();
    void upload();
    void draw();
    
    Cube& setColour(glm::vec3 colour);
    Cube& attachTo(Cube& parent, glm::vec3 anchorPoint, glm::vec3 direction);

    Cube& setTranslation(glm::vec3 distance);
    Cube& translate(glm::vec3 distance);
    Cube& setRotation(glm::vec3 radians);
    Cube& rotate(glm::vec3 radians);
    Cube& scale(glm::vec3 factor);
    Cube& updateModel(); 
};

// human.cpp
class Human {
  private:
    Cube head;
    Cube torso;

    Cube leftUpperArm;
    Cube leftLowerArm;
    Cube rightUpperArm;
    Cube rightLowerArm;
    
    Cube leftUpperLeg;
    Cube leftLowerLeg;
    Cube rightUpperLeg;
    Cube rightLowerLeg;

    Cube tail;

    Movement _movement;
    uint     _movementStage;
    uint     _movementStep;
    std::chrono::steady_clock::time_point _movementStartTime;
  
  public:
    Human();
    void upload();
    void draw();
    void updateModel();

    void rotate();
    void jump();
    void walk();

    void handleJump();
    void handleWalk();
};

inline Human human = Human();
