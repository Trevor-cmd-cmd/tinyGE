#pragma once

// OpenGL
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Engine
#include "mesh.h"
#include "shaders.h"
#include "vector.h"
#include "camera.h"
#include "gameobject.h"
#include "texture.h"

// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Other
#include <cmath>
#include <iostream>

namespace tinyGE
{
    extern Camera* ac;
    extern Shader* as;
    
    void init();
    void makewindow(int width, int height, const char* title);
    bool tick();
}
