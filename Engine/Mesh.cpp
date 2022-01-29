#include "pch.h"
#include "Engine.h"
#include "Mesh.h"
#include "Shader.h"

void Mesh::Init(vector<Vertex>& vec, shared_ptr<Shader> shader)
{
    Vertex* vertices = new Vertex[vec.size()];
    int _vertexCount = vec.size();
    for (int i = 0; i < _vertexCount; i++)
    {
        vertices[i] = vec[i];
    }
    _shader = shader;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    //glGenBuffers(1, &EBO);

    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * _vertexCount, vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    /*unsigned int uniformBlockIndex = glGetUniformBlockIndex(_shader->ID, "transform");
    glUniformBlockBinding(_shader->ID, uniformBlockIndex, 0);
    
    glGenBuffers(1, &uboTransform);*/
}

void Mesh::Render()
{
    _shader->use();
    /*glBindBuffer(GL_UNIFORM_BUFFER, uboTransform);
    glBufferData(GL_UNIFORM_BUFFER, sizeof(Transform), NULL, GL_STATIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);

    glBindBufferRange(GL_UNIFORM_BUFFER, 0, uboTransform, 0, sizeof(Transform));

    glBindBuffer(GL_UNIFORM_BUFFER, uboTransform);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(Transform), &_transform);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);*/
    GEngine->GetCB()->PushData(_shader,&_transform, "transform", 0);
    //_shader->setVec4("transform", _transform.offset);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
