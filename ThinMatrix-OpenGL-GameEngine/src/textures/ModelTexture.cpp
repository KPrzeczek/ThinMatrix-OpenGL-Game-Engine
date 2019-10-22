#include "ModelTexture.h"

ModelTexture::ModelTexture(GLuint ID)
	: m_textureID(ID)
{
}

GLuint ModelTexture::getTextureID() const
{
	return m_textureID;
}