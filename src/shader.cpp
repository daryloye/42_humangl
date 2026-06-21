#include "humangl.h"

const std::string gVertexShaderSource = 
"#version 410 core\n"
"layout(location = 0) in vec4 position;\n"
"void main()\n"
"{\n"
"  gl_Position = vec4(position.x, position.y, position.z, position.w);\n"
"}\n";

const std::string gFragmentShaderSource = 
"#version 410 core\n"
"out vec4 color;\n"
"void main()\n"
"{\n"
"  color = vec4(1.f, 0.5f, 0.0f, 1.0f);\n"		// orange colour triangle
"}\n";


void vertexSpecification() {
	const std::vector<GLfloat> vertexPosition {
		-0.8f, -0.8f, 0.0f,
		0.8f, -0.8f, 0.0f,
		0.0f, 0.8f, 0.0f
	};

	glGenVertexArrays(1, &gVertexArrayObject);
	glBindVertexArray(gVertexArrayObject);

	glGenBuffers(1, &gVertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, gVertexBufferObject);
	glBufferData(	
		GL_ARRAY_BUFFER, 
		vertexPosition.size() * sizeof(GLfloat),
		vertexPosition.data(),
		GL_STATIC_DRAW
	);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glBindVertexArray(0);
	glDisableVertexAttribArray(0);
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
	
	GLuint myVertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
	GLuint myFragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
	if (myVertexShader == 0 || myFragmentShader == 0) {
		glDeleteProgram(programObject);
		return 0;
	}

	glAttachShader(programObject, myVertexShader);
	glAttachShader(programObject, myFragmentShader);
	glLinkProgram(programObject);
	glDeleteShader(myVertexShader);
	glDeleteShader(myFragmentShader);

	glValidateProgram(programObject);

	return programObject;
}


void createGraphicsPipeline() {
	gGraphicsPipelineShaderProgram = createShaderProgram(gVertexShaderSource, gFragmentShaderSource);
	if (gGraphicsPipelineShaderProgram == 0)
		exit(1);
}
