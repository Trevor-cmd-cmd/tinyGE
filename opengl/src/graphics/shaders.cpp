#include <glad.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
#include "shaders.h"

Shader::Shader(const char* v, const char* f)
    : shaderProgramm(0), vertexShaderS(v), fragmentShaderS(f) {}

void Shader::createShader()
{
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderS, nullptr);
    glCompileShader(vertexShader);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderS, nullptr);
    glCompileShader(fragmentShader);

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    shaderProgramm = shaderProgram;
}

std::string openShader(const std::string& filePath)
{
    
    std::filesystem::path currentFile = __FILE__;
    const std::string h = currentFile.parent_path().parent_path();
    std::cout << h + "/assets/shaders/" + filePath << "\n";
    std::ifstream file(h + "/assets/shaders/" + filePath);
    if (file.is_open())
    {
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    } else { std::cout << "Failed to open shader " << filePath << "\n"; }
    
    return "";
}
