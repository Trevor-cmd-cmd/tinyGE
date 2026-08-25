#pragma once

#include "mesh.h"
#include "shaders.h"
#include "vector.h"
#include "transform.h"
struct GameObject
{
    Transform transform;
    
    Mesh* mesh;
    Shader* shader;
};