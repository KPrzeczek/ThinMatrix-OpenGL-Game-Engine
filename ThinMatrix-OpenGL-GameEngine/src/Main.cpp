#include <SFML/Graphics.hpp>
#include <Gl/glew.h>

#include <vector>

#include "renderEngine/DisplayManager.h"
#include "renderEngine/Renderer.h"
#include "renderEngine/Loader.h"

#include "models/RawModel.h"
#include "models/TexturedModel.h"

#include "textures/ModelTexture.h"

#include "entities/Entity.h"

#include "shaders/StaticShader.h"

int main()
{
	DisplayManager::Create();

	Loader loader;
	Renderer renderer;
	StaticShader shader;

	std::vector<GLfloat> vertices = {
		-0.5f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.5f, 0.5f, 0.0f
	};

	std::vector<GLuint> indices = {
		0, 1, 3, // V0, V1, V3 (TL Triangle)
		3, 1, 2  // V3, V1, V2 (BR Triangle)
	};

	std::vector<GLfloat> textureCoords = {
		0, 0, // V0
		0, 1, // V1
		1, 1, // V2
		1, 0  // V3
	};

	RawModel model = loader.loadToVAO(vertices, indices, textureCoords);
	ModelTexture texture = loader.loadTexture("testStatic");

	TexturedModel entityModel(model, texture);

	Entity entity(entityModel, {-1, 0, 0}, {0, 0, 0}, {1, 1, 1});


	while(DisplayManager::isOpen())
	{
		DisplayManager::Update();

		shader.Start();

		DisplayManager::Refresh(255, 0, 0, 255);
		renderer.Render(entity, shader);

		shader.Stop();

		DisplayManager::CheckForClose();
	}

	return 0;
}