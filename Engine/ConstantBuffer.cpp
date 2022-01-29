#include "pch.h"
#include "ConstantBuffer.h"
#include "Shader.h"
void ConstantBuffer::Init(uint32 size)
{
    _size = size;
	CreateBuffer();
}

void ConstantBuffer::Clear()
{
}

void ConstantBuffer::PushData(shared_ptr<Shader>shader,void* buffer, const GLchar* uniformBlockName, GLuint bindingPoint )
{
   
    unsigned int uniformBlockIndex = glGetUniformBlockIndex(shader->ID, uniformBlockName);
    glUniformBlockBinding(shader->ID, uniformBlockIndex, bindingPoint);
    glBindBufferRange(GL_UNIFORM_BUFFER, 0, _cbvBuffer, 0, _size);
    glBindBuffer(GL_UNIFORM_BUFFER, _cbvBuffer);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, _size, buffer);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void ConstantBuffer::CreateBuffer()
{
    glGenBuffers(1, &_cbvBuffer);
    glBindBuffer(GL_UNIFORM_BUFFER, _cbvBuffer);
    glBufferData(GL_UNIFORM_BUFFER, _size, NULL, GL_STATIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}
