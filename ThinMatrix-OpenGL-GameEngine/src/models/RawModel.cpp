#include "RawModel.h"

RawModel::RawModel(GLuint vaoID,
				   GLuint vertexCount)
	: m_vaoID(vaoID)
	, m_vertexCount(vertexCount)
{
}

GLuint RawModel::getVaoID()
{
	return m_vaoID;
}

GLuint RawModel::getVertexCount()
{
	return m_vertexCount;
}