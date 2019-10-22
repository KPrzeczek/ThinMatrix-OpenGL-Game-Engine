#pragma once

namespace DisplayManager
{

void Create();
void Update();
void Close();
void Refresh(float R, float G, float B, float A);
void CheckForClose();

bool isOpen();

}