#pragma once
class ConstantBuffer
{

	//ConstantBuffer();
	//~ConstantBuffer();
public:
	void Init(uint32 size);

	void Clear();
	void PushData(shared_ptr<class Shader>shader, void* buffer, const GLchar* uniformBlockName, GLuint bindingPoint);

	//D3D12_GPU_VIRTUAL_ADDRESS GetGpuVirtualAddress(uint32 index);

private:
	void CreateBuffer();

private:
	unsigned int	_cbvBuffer;
	uint32			_size = 0;
	BYTE* _mappedBuffer = nullptr;

};

