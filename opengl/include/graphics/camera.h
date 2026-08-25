#pragma once

#include "vector.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
struct Camera
{
    glm::vec3 position;

    Camera(glm::vec3 pos = {0, 0, 0});
    void UpdateCamera(glm::vec3 pos, const char* name, unsigned int shaderProgram);
    void use();
};
