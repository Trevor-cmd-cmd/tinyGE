#pragma once

#include <string>
#include "vector.h"

enum class ShaderType{ basic, };

struct Shader
{
    public:
        unsigned int shaderProgramm;
    
    ShaderType type;

    Shader(ShaderType t);
    void createShader();
    
};

std::string openShader(const std::string& filePath);

struct ShaderSourcePaths {
    std::string vertexPath;
    std::string fragmentPath;
};


ShaderSourcePaths getShaderPaths(ShaderType type);
