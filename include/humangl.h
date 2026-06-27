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

#define SCREEN_HEIGHT   600
#define SCREEN_WIDTH    800

inline SDL_Window* gWindow = nullptr;
inline SDL_GLContext gGLContext = nullptr;

inline glm::vec2 gDepthOffset = glm::vec2(0.25f, 0.25f);

inline bool isRunning = true;
inline float g_offset = 0.0f;

inline GLuint gVertexArrayObject = 0;
inline GLuint gVertexBufferObject = 0;
inline GLuint gColourArrayObject = 0;
inline GLuint gColourBufferObject = 0;

inline GLuint gGraphicsPipelineShaderProgram = 0;

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
    std::vector<glm::vec3>	_vertices;
    std::vector<GLuint>			_indices;
  
    glm::vec3               _center;
    glm::vec3               _scale;

		GLuint	_vao;
		GLuint	_vbo;
  
  public:
    Cube(glm::vec3 center);
    
    void upload();
    void draw();

    void scale(glm::vec3 factor);
};

inline Cube c = Cube( glm::vec3(0, 0, 0) );
