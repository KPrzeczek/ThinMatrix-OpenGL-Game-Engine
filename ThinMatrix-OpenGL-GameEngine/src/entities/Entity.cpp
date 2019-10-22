#include "Entity.h"

Entity::Entity(const TexturedModel& model,
			   glm::vec3 position,
			   glm::vec3 rotation,
			   glm::vec3 scale)
	: m_model(&model)
	, m_position(position)
	, m_rotation(rotation)
	, m_scale(scale)
{
}

void Entity::Move(const glm::vec3& offset)
{
	m_position.x += offset.x;
	m_position.y += offset.y;
	m_position.z += offset.z;
}

void Entity::SetPosition(const glm::vec3& offset)
{
	m_position.x = offset.x;
	m_position.y = offset.y;
	m_position.z = offset.z;
}

void Entity::Rotate(const glm::vec3& offset)
{
	m_rotation.x += offset.x;
	m_rotation.y += offset.y;
	m_rotation.z += offset.z;
}

void Entity::SetRotation(const glm::vec3& offset)
{
	m_rotation.x = offset.x;
	m_rotation.y = offset.y;
	m_rotation.z = offset.z;
}

void Entity::Scale(const glm::vec3& offset)
{
	m_scale.x += offset.x;
	m_scale.y += offset.y;
	m_scale.z += offset.z;
}

void Entity::SetScale(const glm::vec3& offset)
{
	m_scale.x = offset.x;
	m_scale.y = offset.y;
	m_scale.z = offset.z;
}

const TexturedModel& Entity::getModel() const
{
	return* m_model;
}

const glm::vec3& Entity::getPosition() const
{
	return m_position;
}

const glm::vec3& Entity::getRotation() const
{
	return m_rotation;
}

const glm::vec3& Entity::getScale() const
{
	return m_scale;
}