#pragma once

#include <vector>
#include "vector.h"
#include <glm/glm.hpp>

struct Vertex
{
    glm::vec3 position;
    glm::vec2 uv;

    Vertex(glm::vec3 pos, glm::vec2 uv = {0, 0})
        : position(pos), uv(uv) {}
};
struct Mesh
{
    private:    
        unsigned int VAO, VBO, EBO;    
        
    public:
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
    
    Mesh(const std::vector<Vertex>& verts, const std::vector<unsigned int>& inds);
    ~Mesh();
    void create();
    void upload();
    void render();
};
