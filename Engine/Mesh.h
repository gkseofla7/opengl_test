#pragma once
class Mesh
{
public:
	void Init(vector<Vertex>& vec);
	void Render();

	void SetTransform(const Transform& t) { _transform = t; }

private:
	unsigned int VBO, VAO, EBO;
	
	uint32 _vertexCount = 0;

	Transform _transform = {};
};

