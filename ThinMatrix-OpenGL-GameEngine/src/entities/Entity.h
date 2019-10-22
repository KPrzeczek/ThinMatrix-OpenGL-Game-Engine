#pragma once

#include <glm/glm.hpp>

class TexturedModel;

class Entity
{
public:
	Entity(const TexturedModel& model,
		   glm::vec3 position,
		   glm::vec3 rotation,
		   glm::vec3 scale);

	void Move(const glm::vec3& offset);
	void SetPosition(const glm::vec3& offset);

	void Rotate(const glm::vec3& offset);
	void SetRotation(const glm::vec3& offset);

	void Scale(const glm::vec3& offset);
	void SetScale(const glm::vec3& offset);

	const TexturedModel& getModel() const;

	const glm::vec3& getPosition() const;
	const glm::vec3& getRotation() const;
	const glm::vec3& getScale() const;

private:
	const TexturedModel* m_model;
	
	glm::vec3 m_position;
	glm::vec3 m_rotation;
	glm::vec3 m_scale;

};