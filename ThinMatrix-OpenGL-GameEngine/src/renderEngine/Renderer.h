#pragma once

class Entity;
class StaticShader;

class Renderer
{
public:
	void Render(Entity& entity, StaticShader& shader);

};