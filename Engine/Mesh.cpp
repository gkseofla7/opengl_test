#include "pch.h"
#include "Mesh.h"

void Mesh::Init(vector<Vertex>& vec)
{
    Vertex* vertices = new Vertex[vec.size()];
    int _vertexCount = vec.size();
    for (int i = 0; i < _vertexCount; i++)
    {
        vertices[i] = vec[i];
    }
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    //glGenBuffers(1, &EBO);

    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * _vertexCount, vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(Vertex), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

}

void Mesh::Render()
{
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, _vertexCount, GL_UNSIGNED_INT, 0);
}
