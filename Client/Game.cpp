#include "pch.h"
#include "Game.h"
#include "Engine.h"
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

shared_ptr<Mesh> mesh = make_shared<Mesh>();
shared_ptr<Shader> shader = make_shared<Shader>();

void Game::Init(GLFWwindow* _window)
{
    GEngine->Init(_window);
	vector<Vertex> vec(3);
	vec[0].pos = Vec3(0.f, 0.5f, 0.5f);
	vec[0].color = Vec4(1.f, 0.f, 0.f, 1.f);
	vec[1].pos = Vec3(0.5f, -0.5f, 0.5f);
	vec[1].color = Vec4(0.f, 1.0f, 0.f, 1.f);
	vec[2].pos = Vec3(-0.5f, -0.5f, 0.5f);
	vec[2].color = Vec4(0.f, 0.f, 1.f, 1.f);
	
	shader->Init("simple.vshader", "simple.fshader");
	mesh->Init(vec, shader);
}

void Game::Update()
{
	GEngine->RenderBegin();

	shader->use();

	{
		Transform t;
		t.offset = Vec4(0.75f, 0.f, 0.f, 0.f);
		mesh->SetTransform(t);
		mesh->Render();
	}

	{
		Transform t;
		t.offset = Vec4(0.f, 0.75f, 0.f, 0.f);
		mesh->SetTransform(t);
		mesh->SetShader(shader);
		mesh->Render();
	}

	GEngine->RenderEnd();
}








