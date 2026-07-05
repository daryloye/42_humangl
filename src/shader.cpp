#include "humangl.h"

// Defines the vertex geometry
void vertexSpecification() {
	human.head.translate(glm::vec3(0, 0.25, 0));
	human.head.rotate(glm::radians(45.0f), glm::vec3(0, 0, 1));
	human.head.scale(glm::vec3(0.25));

	human.torso.translate(glm::vec3(0.5, -0.25, 0));
	human.torso.rotate(glm::radians(45.0f), glm::vec3(0, 1, 0));
	human.torso.scale(glm::vec3(0.25));
	
	human.upload();
}


GLuint compileShader(GLuint type, const std::string& source) {
	GLuint shaderObject = glCreateShader(type);

	if (shaderObject == 0)
		return 0;

	const char* src = source.c_str();
	glShaderSource(shaderObject, 1, &src, nullptr);
	glCompileShader(shaderObject);

	return shaderObject;
}


GLuint createShaderProgram(const std::string& vertexShaderSource, const std::string& fragmentShaderSource) {
	GLuint programObject = glCreateProgram();
	
	GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
	GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
	if (vertexShader == 0 || fragmentShader == 0) {
		glDeleteProgram(programObject);
		return 0;
	}

	glAttachShader(programObject, vertexShader);
	glAttachShader(programObject, fragmentShader);
	glLinkProgram(programObject);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	glValidateProgram(programObject);

	return programObject;
}


std::string getShaderSource(const std::string& filename) {
  std::ifstream file(filename.c_str());

  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    exit(1);
  }

  std::string source = "";
  std::string line;
  while (std::getline(file, line)) {
    source += line + "\n";
  }

  file.close();

  return source;
}


void createGraphicsPipeline() {
	std::string vertexShaderFile = "./shaders/cube.vert";		// define the vertices
	std::string fragmentShaderFile = "./shaders/cube.frag";		// defines the colours
	
	gShaderProgram = createShaderProgram(
		getShaderSource(vertexShaderFile), 
		getShaderSource(fragmentShaderFile)
	);
	if (gShaderProgram == 0) {
		exit(1);
	}
}
