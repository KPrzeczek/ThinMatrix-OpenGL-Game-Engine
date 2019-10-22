#include "Loader.h"
#include "../models/RawModel.h"

#include <SFML/Graphics.hpp>
#include <GL/glew.h>

// CleanUp
Loader::~Loader()
{
	for(auto& VAO : VAOs)
	{
		glDeleteVertexArrays(1, &VAO);
	}
	for(auto& VBO : VBOs)
	{
		glDeleteBuffers(1, &VBO);
	}
	for(auto& TXR : Textures)
	{
		glDeleteTextures(1, &TXR);
	}
}


GLuint Loader::loadTexture(std::string name)
{
	sf::Image img;
	img.loadFromFile("res/txrs/" + name + ".png");

	//img.flipVertically();
	//img.flipHorizontally();

	GLuint txrID;
	glGenTextures(1, &txrID);
	
	glBindTexture(GL_TEXTURE_2D, txrID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
				 img.getSize().x, img.getSize().y,
				 0, GL_RGBA, GL_UNSIGNED_BYTE,
				 img.getPixelsPtr());
	Textures.push_back(txrID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	return txrID;
}

RawModel Loader::loadToVAO(std::vector<GLfloat>& positions,
						   std::vector<GLuint>& indices,
						   std::vector<GLfloat>& textureCoords)
{
	GLuint ID = createVAO();

	BindIndicesBuffer(indices);
	StoreDataInAttributeList(0, 3, positions);
	StoreDataInAttributeList(1, 2, textureCoords);

	UnbindVAO();
	return {ID, static_cast<GLuint>(indices.size())};
}

GLuint Loader::createVAO()
{
	GLuint ID;

	glGenVertexArrays(1, &ID);
	glBindVertexArray(ID);

	VAOs.push_back(ID);

	return ID;
}

GLuint Loader::createVBO(GLenum type)
{
	GLuint ID;

	glGenBuffers(1, &ID);
	glBindBuffer(type, ID);

	VBOs.push_back(ID);

	return ID;
}

void Loader::BindIndicesBuffer(std::vector<GLuint>& indices)
{
	createVBO(GL_ELEMENT_ARRAY_BUFFER);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
				 indices.size() * sizeof(indices.at(0)),
				 indices.data(),
				 GL_STATIC_DRAW);
}

void Loader::UnbindVAO()
{
	glBindVertexArray(0);
}
