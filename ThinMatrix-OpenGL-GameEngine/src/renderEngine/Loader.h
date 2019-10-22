#pragma once

#include <GL/glew.h>

#include <string>
#include <vector>

class RawModel;

class Loader
{
public:
	~Loader();

	GLuint loadTexture(std::string name);
	RawModel loadToVAO(std::vector<GLfloat>& positions,
					   std::vector<GLuint>& indices,
					   std::vector<GLfloat>& textureCoords);

private:
	GLuint createVAO();
	GLuint createVBO(GLenum type);

	void BindIndicesBuffer(std::vector<GLuint>& indices);
	void UnbindVAO();

	std::vector<GLuint> VAOs;
	std::vector<GLuint> VBOs;
	std::vector<GLuint> Textures;

	template<typename T>
	void StoreDataInAttributeList(GLuint attributeNumber,
								  GLuint coordCount,
								  std::vector<T>& data);
};

template<typename T>
void Loader::StoreDataInAttributeList(GLuint attribNo,
							  GLuint coordCount,
							  std::vector<T>& data)
{
	createVBO(GL_ARRAY_BUFFER);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(data.at(0)), data.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(attribNo, coordCount, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
	glEnableVertexAttribArray(attribNo);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}