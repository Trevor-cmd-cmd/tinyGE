#pragma once

#include "mesh.h"
#include "shaders.h"
#include "vector.h"
#include "camera.h"
#include <glad.h>
#include <GLFW/glfw3.h>
namespace eng
{
    void init();
    void makewindow(int width, int height, const char* title);
    bool tick();
}
