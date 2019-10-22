#include "Renderer.h"

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "../models/RawModel.h"
#include "../models/TexturedModel.h"
#include "../textures/ModelTexture.h"

#include "../entities/Entity.h"

#include "../shaders/StaticShader.h"

#include "../util/Maths.h"


void Renderer::Render(Entity& entity, StaticShader& shader)
{
	TexturedModel texturedModel = entity.getModel();
	RawModel model = texturedModel.getRawModel();

	glBindVertexArray(model.getVaoID());

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glm::mat4 transformationMatrix = maths::createTransformationMatrix(entity.getPosition(),
																	   entity.getRotation(),
																	   entity.getScale());
	shader.loadTransformationMatrix(transformationMatrix);

	glActiveTexture(GL_TEXTURE0);

	glBindTexture(GL_TEXTURE_2D, texturedModel.getModelTexture().getTextureID());
	glDrawElements(GL_TRIANGLES, model.getVertexCount(), GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	glBindVertexArray(0);
}
