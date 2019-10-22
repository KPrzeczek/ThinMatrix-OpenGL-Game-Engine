#include "StaticShader.h"

#include <iostream>

StaticShader::StaticShader()
	: ShaderProgram("res/sdrs/vertexShader.glsl", "res/sdrs/fragmentShader.glsl")
{
	CreateProgram();
}

void StaticShader::loadTransformationMatrix(glm::mat4& matrix4)
{
	LoadMatrix4(loc_transformationMatrix, matrix4);
}

void StaticShader::BindAttribs()
{
	BindAttrib(0, "position");
	BindAttrib(1, "textureCoords");
}

void StaticShader::GetAllUniformLocations()
{
	loc_transformationMatrix = getUniformLocation("transformationMatrix");
}