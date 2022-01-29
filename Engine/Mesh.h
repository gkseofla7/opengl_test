#pragma once
class Shader;
class Mesh
{
public:
	void Init(vector<Vertex>& vec, shared_ptr<Shader> shader);
	void Render();

	void SetTransform(const Transform& t) { _transform = t; }
	void SetShader(const shared_ptr<Shader> shader) { _shader = shader; }
private:
	unsigned int VBO, VAO, EBO;
	unsigned int uboTransform;
	uint32 _vertexCount = 0;
	shared_ptr<Shader> _shader;
	Transform _transform = {};
};

