#include "humangl.h"

// Defines the vertex geometry
void vertexSpecification() {
	const std::vector<GLfloat> vertexPosition {
		-0.8f, -0.8f, 0.0f,
		0.8f, -0.8f, 0.0f,
		0.0f, 0.8f, 0.0f
	};
  
  const std::vector<GLfloat> vertexColours {
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f
  };
  
  // generate and bind vertex array object (VAO)
	glGenVertexArrays(1, &gVertexArrayObject);
	glBindVertexArray(gVertexArrayObject);

  // 1st VBO for vertex positions
	glGenBuffers(1, &gVertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, gVertexBufferObject);
	glBufferData(	
		GL_ARRAY_BUFFER, 
		vertexPosition.size() * sizeof(GLfloat),
		vertexPosition.data(),
		GL_STATIC_DRAW
	);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);   // Array 0 has 3 floats per vertex

  // 2nd VBO for colours
	glGenBuffers(1, &gColourBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, gColourBufferObject);
	glBufferData(	
		GL_ARRAY_BUFFER, 
		vertexColours.size() * sizeof(GLfloat),
		vertexColours.data(),
		GL_STATIC_DRAW
	);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);   // Array 1 has 3 floats per vertex

	glBindVertexArray(0);
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
  // vertex shader defines the vertices of the shape
  // fragment shader defines the colour in the shape

  std::string vertexShaderFile = "./shaders/triangle.vert";
  std::string fragmentShaderFile = "./shaders/triangle.frag";

	gGraphicsPipelineShaderProgram = createShaderProgram( 
    getShaderSource(vertexShaderFile), 
    getShaderSource(fragmentShaderFile)
  );
	if (gGraphicsPipelineShaderProgram == 0)
		exit(1);
}
