#pragma once

// stb_image - v2.27 - public domain image loader - http://github/nothings/stb
#include "stb/stb_image.h"
#include <filesystem>
#include <glad/glad.h>
struct Texture
{
    private:
        unsigned int textureID;
    public:
        std::string path;
    
    Texture(const std::string& path);
    void bindTexture();
    void h();
};

