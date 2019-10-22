#pragma once

#include <GL/glew.h>

class ModelTexture
{
public:
	ModelTexture(GLuint ID);

	GLuint getTextureID() const;

private:
	GLuint m_textureID;

};