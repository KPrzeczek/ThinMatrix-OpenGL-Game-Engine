#include "ShaderLoader.h"

#include <fstream>
#include <stdexcept>
#include <sstream>

// This is not my code! I had extreme troubles with this :/
// It belongs to Hopson
// https://github.com/Hopson97
// Complete credit to him.

namespace
{

std::string getSource(const std::string& filePath);
GLuint compileShader(const GLchar* source, GLenum type);

void CheckForErrors(GLuint id, GLenum status, const std::string& errorType);

std::string getSource(const std::string& filePath)
{
	std::ifstream inFile;

	inFile.exceptions(std::ifstream::badbit);
	inFile.open(filePath);

	if(!inFile.is_open())
	{
		throw std::runtime_error("Unable to open " + filePath);
	}

	std::string source;

	try
	{
		inFile.open(filePath);
		std::stringstream stream;
		stream << inFile.rdbuf();
		source = stream.str();
	} 
	catch(std::ifstream::failure e)
	{
		throw std::runtime_error("Unable to read shader: " + filePath);
	}

	return source;
}

GLuint compileShader(const GLchar* source, GLenum type)
{
	GLuint id;

	id = glCreateShader(type);
	glShaderSource(id, 1, &source, NULL);
	glCompileShader(id);

	CheckForErrors(id, GL_COMPILE_STATUS, "Failure compiling shader of type: " + type);
	return id;
}

void CheckForErrors(GLuint id, GLenum status, const std::string& errorType)
{
	GLint success;
	GLchar infoLog[512];

	glGetShaderiv(id, status, &success);

	if(!success)
	{
		glGetShaderInfoLog(id, 512, NULL, infoLog);
		throw std::runtime_error(errorType + "\n Error is: " + infoLog);
	}
}
}

void  LoadShader(const std::string& vertexFilePath,
				 const std::string& fragmentFilePath,
				 GLuint& id, GLuint& vertexId, GLuint& fragmentId)
{
	std::string vertexSource = getSource(vertexFilePath);
	std::string fragmentSource = getSource(fragmentFilePath);

	vertexId =		compileShader(vertexSource.c_str(), GL_VERTEX_SHADER);
	fragmentId =	compileShader(fragmentSource.c_str(), GL_FRAGMENT_SHADER);
}