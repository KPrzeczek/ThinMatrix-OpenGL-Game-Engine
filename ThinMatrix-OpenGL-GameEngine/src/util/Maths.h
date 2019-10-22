#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>

namespace maths
{

glm::mat4 createTransformationMatrix(const glm::vec3& translation,
									 const glm::vec3& rotation,
									 const glm::vec3& scale)
{
	glm::mat4 matrix;


	matrix = glm::translate(matrix, translation);

	matrix = glm::rotate(matrix, glm::radians(rotation.x), {1, 0, 0});
	matrix = glm::rotate(matrix, glm::radians(rotation.y), {0, 1, 0});
	matrix = glm::rotate(matrix, glm::radians(rotation.z), {0, 0, 1});

	matrix = glm::scale(matrix, scale);

	return matrix;
}

}