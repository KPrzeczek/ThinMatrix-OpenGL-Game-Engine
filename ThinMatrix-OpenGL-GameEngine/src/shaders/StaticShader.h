#pragma once

#include <glm/glm.hpp>
#include <string>

#include "ShaderProgram.h"
class StaticShader :
	public ShaderProgram
{
public:
	StaticShader();

	void loadTransformationMatrix(glm::mat4& matrix4);

protected:
	void BindAttribs() override;
	void GetAllUniformLocations() override;

	GLuint loc_transformationMatrix;

};