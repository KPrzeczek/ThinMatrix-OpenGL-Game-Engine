#include "ShaderProgram.h"
#include "ShaderLoader.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

ShaderProgram::ShaderProgram(const std::string& vertexFile, const std::string& fragmentFile)
{
	LoadShader(vertexFile, fragmentFile,
			   m_programID,
			   m_vertexID, m_fragmentID);
}

ShaderProgram::ShaderProgram(GLuint programID, GLuint vertexID, GLuint fragmentID)
	: m_programID(programID)
	, m_vertexID(vertexID)
	, m_fragmentID(fragmentID)
{
}

ShaderProgram::~ShaderProgram()
{
	Stop();

	glDetachShader(m_programID, m_vertexID);
	glDetachShader(m_programID, m_fragmentID);

	glDeleteShader(m_vertexID);
	glDeleteShader(m_fragmentID);

	glDeleteProgram(m_programID);
}

void ShaderProgram::Start()
{
	glUseProgram(m_programID); 
}

void ShaderProgram::Stop()
{
	glUseProgram(0);
}

GLuint ShaderProgram::getUniformLocation(const std::string& name) const
{
	return glGetUniformLocation(m_programID, name.c_str());
}

void ShaderProgram::BindAttrib(GLuint attrib, const std::string& name) const
{
	glBindAttribLocation(m_programID, attrib, name.c_str());
}

void ShaderProgram::CreateProgram()
{
	m_programID = glCreateProgram();

	glAttachShader(m_programID, m_vertexID);
	glAttachShader(m_programID, m_fragmentID);

	BindAttribs();

	glLinkProgram(m_programID);
	glValidateProgram(m_programID);

	GetAllUniformLocations();

	glDeleteShader(m_vertexID);
	glDeleteShader(m_fragmentID);
}

void ShaderProgram::LoadBool(GLuint location, bool value) const
{
	glUniform1i(location, value);
}

void ShaderProgram::LoadFloat(GLuint location, GLfloat value) const
{
	glUniform1f(location, value);
}

void ShaderProgram::LoadVector3(GLuint location, const glm::vec3& value) const
{
	glUniform3f(location, value.x, value.y, value.z);
}

void ShaderProgram::LoadMatrix4(GLuint location, const glm::mat4& matrix4) const
{
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix4));
}