#pragma once

#include "mesh.h"
#include "shaders.h"
#include "vector.h"

struct GameObject
{
    Vector3 position;
    Vector3 scale;
    Vector3 rotation;
    Mesh* mesh;
    Shader* shader;
};