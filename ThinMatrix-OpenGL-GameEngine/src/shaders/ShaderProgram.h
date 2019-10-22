#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <string>

class ShaderProgram
{
public:
	ShaderProgram(const std::string& vertexFile,
				  const std::string& fragmentFile);
	ShaderProgram(GLuint programID, GLuint vertexID, GLuint fragmentID);
	~ShaderProgram();

	void Start();
	void Stop();

protected:
	GLuint getUniformLocation(const std::string& name) const;

	virtual void BindAttribs() = 0;
	virtual void GetAllUniformLocations() = 0;

	void BindAttrib(GLuint attrib, const std::string& name) const;
	void CreateProgram();

	void LoadBool		(GLuint location, bool value)				const;
	void LoadFloat		(GLuint location, GLfloat value)			const;
	void LoadVector3	(GLuint location, const glm::vec3& value)	const;
	void LoadMatrix4	(GLuint location, const glm::mat4& matrix4)	const;

private:
	GLuint m_programID;
	GLuint m_vertexID;
	GLuint m_fragmentID;

};