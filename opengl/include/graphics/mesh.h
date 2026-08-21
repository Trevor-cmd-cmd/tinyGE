#pragma once

#include <vector>
#include "vector.h"
struct Mesh
{
    std::vector<Vector3> vertices;
    std::vector<unsigned int> indices;
    unsigned int VAO, VBO, EBO;
    
    Mesh(const std::vector<Vector3>& verts, const std::vector<unsigned int>& inds);
    void createMesh();
    void renderMesh();
    void updateMesh(const std::vector<Vector3>& newVertices);
};
