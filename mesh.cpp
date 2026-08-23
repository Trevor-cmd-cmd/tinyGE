#include "mesh.h"
#include <glad.h>
#include "vector.h"
#include <vector>

Mesh::Mesh(const std::vector<Vector3>& verts, const std::vector<unsigned int>& inds, const std::vector<Vector2>& uvs)
    : vertices(verts), uvs(uvs), indices(inds), VAO(0), VBO(0), EBO(0) { createMesh(); }
;
void Mesh::createMesh()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // Interleave positions (3 floats) and UVs (2 floats)
    
    
    size_t vertCount = vertices.size();
    buffer.reserve(vertCount * 5);
    for (size_t i = 0; i < vertCount; ++i)
    {
        buffer.push_back(vertices[i].x);
        buffer.push_back(vertices[i].y);
        buffer.push_back(vertices[i].z);
        if (uvs.size() == vertCount)
        {
            buffer.push_back(uvs[i].x);
            buffer.push_back(uvs[i].y);
        }
        else
        {
            buffer.push_back(vertices[i].x);
            buffer.push_back(vertices[i].y);
        }
    }
    glBufferData(GL_ARRAY_BUFFER, buffer.size() * sizeof(float), buffer.data(), GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_DYNAMIC_DRAW);

    // position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // uv
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

void Mesh::renderMesh()
{
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}


void Mesh::updateMesh()
{
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, static_cast<GLsizeiptr>(buffer.size() * sizeof(float)), buffer.data());
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
