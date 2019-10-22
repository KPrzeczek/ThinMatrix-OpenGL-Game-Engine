#pragma once

#include <GL/glew.h>

class RawModel
{
public:
	RawModel(GLuint vaoID,
			 GLuint vertexCount);

	GLuint getVaoID();
	GLuint getVertexCount();

private:
	GLuint m_vaoID;
	GLuint m_vertexCount;

};