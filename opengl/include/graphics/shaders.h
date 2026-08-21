#pragma once

#include <string>
#include "vector.h"
struct Shader
{
    unsigned int shaderProgramm;
    const char* vertexShaderS;
    const char* fragmentShaderS;

    Shader(const char* v, const char* f);
    void createShader();
    
};

std::string openShader(const std::string& filePath);
