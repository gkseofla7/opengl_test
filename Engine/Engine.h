#pragma once
#include "Mesh.h"
#include "Shader.h"
#include "ConstantBuffer.h"
class Engine
{
public:

	void Init(GLFWwindow* window);
	void Render();
	void RenderBegin();
	void RenderEnd();
	shared_ptr<ConstantBuffer> GetCB() { return _cb; }

private:
	

private:
	GLFWwindow* window;
	shared_ptr<ConstantBuffer> _cb;
};

