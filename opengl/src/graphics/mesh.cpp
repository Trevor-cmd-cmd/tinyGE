#include "mesh.h"
#include <glad.h>
#include "vector.h"


Mesh::Mesh(const std::vector<Vector3>& verts, const std::vector<unsigned int>& inds)
    : vertices(verts), indices(inds), VAO(0), VBO(0), EBO(0) {}

void Mesh::createMesh()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * (sizeof(float) * 3), vertices.data(), GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_DYNAMIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

void Mesh::renderMesh()
{
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}
void Mesh::updateMesh(const std::vector<Vector3>& vertices)
{
    if (vertices.empty())
        return;

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferSubData(GL_ARRAY_BUFFER, 0, static_cast<GLsizeiptr>(vertices.size() * sizeof(Vector3)), vertices.data());

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
