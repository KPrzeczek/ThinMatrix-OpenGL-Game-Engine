#pragma once

#include <GL/glew.h>
#include <string>

#include "ShaderProgram.h"

// This is not my code! I had extreme troubles with this :/
// It belongs to Hopson
// https://github.com/Hopson97
// Complete credit to him.

void LoadShader(const std::string& vertexFilePath,
				const std::string& fragmentFilePath,
				GLuint& id, GLuint& vertexId, GLuint& fragmentId);