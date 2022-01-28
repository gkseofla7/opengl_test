#pragma once
#include "Mesh.h"
#include "Shader.h"
class Engine
{
public:

	void Init(GLFWwindow* window);
	void Update();


private:
	void Render();
	void RenderBegin();
	void RenderEnd();

private:
	GLFWwindow* window;
};

