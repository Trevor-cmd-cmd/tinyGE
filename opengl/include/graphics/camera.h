#pragma once

#include "vector.h"
#include <glad.h>

struct Camera
{
    Vector3 position;

    Camera(Vector3 pos);
    void UpdateCamera(Vector3 pos, const char* name, unsigned int shaderProgram);
};
