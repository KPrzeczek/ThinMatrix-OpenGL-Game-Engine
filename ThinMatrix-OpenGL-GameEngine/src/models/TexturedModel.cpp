#include "TexturedModel.h"

#include "RawModel.h"
#include "../textures/ModelTexture.h"

TexturedModel::TexturedModel(RawModel& model, ModelTexture& texture)
	: m_rawModel(&model)
	, m_modelTexture(&texture)
{
}

const RawModel& TexturedModel::getRawModel() const
{
	return* m_rawModel;
}

const ModelTexture& TexturedModel::getModelTexture() const
{
	return* m_modelTexture;
}