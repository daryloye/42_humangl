#include "humangl.h"

void initialize() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "SDL could not be initialized: " << SDL_GetError() << std::endl;
		exit(1);
	}

	// use OpenGL 4.1 core version
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	gWindow = SDL_CreateWindow(
		"humangl",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_OPENGL
	);

	if (gWindow == nullptr) {
		std::cerr << "Could not create window: " << SDL_GetError() << std::endl;
		exit(1);
	}

	gGLContext = SDL_GL_CreateContext(gWindow);
	if (gGLContext == nullptr) {
		std::cerr << "Could not create OpenGL context: " << SDL_GetError() << std::endl;
		exit(1);
	}

	if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress)) {
		std::cerr << "Could not initialize GLAD library" << std::endl;
		exit(1);
	}

	std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl; 
	std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl; 
	std::cout << "Version: " << glGetString(GL_VERSION) << std::endl; 
	std::cout << "Shading Language: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl; 
}


void input() {
	SDL_Event event;

	while (SDL_PollEvent(&event) != 0) {
		switch (event.type) {
			case SDL_QUIT:
				isRunning = false;
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_UP:
						g_offset += 0.01;
						break;
					case SDLK_DOWN:
						g_offset -= 0.01;
						break;
				}
				break;
		}
	}
}


void draw() {
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);

	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	glClearColor(0, 0, 0, 0);								// black colour background
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	
	glUseProgram(gShaderProgram);
	human.draw();
	glUseProgram(0);		// stop using shader program
}


void loop() {
	while (isRunning) {
		input();
		draw();
		SDL_GL_SwapWindow(gWindow);
	}
}


void cleanup() {
  SDL_DestroyWindow(gWindow);
  SDL_Quit();
}
