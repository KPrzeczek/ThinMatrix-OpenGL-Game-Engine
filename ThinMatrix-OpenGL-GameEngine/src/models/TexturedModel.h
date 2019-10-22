#pragma once

class RawModel;
class ModelTexture;

class TexturedModel
{
public:
	TexturedModel(RawModel& model, ModelTexture& texture);

	const RawModel& getRawModel() const;
	const ModelTexture& getModelTexture() const;

private:
	RawModel* m_rawModel;
	ModelTexture* m_modelTexture;

};