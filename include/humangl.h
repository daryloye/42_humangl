#pragma once

#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <vector>

#define SCREEN_HEIGHT   600
#define SCREEN_WIDTH    800

inline SDL_Window* gWindow = nullptr;
inline SDL_GLContext gGLContext = nullptr;

inline bool isRunning = true;

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
