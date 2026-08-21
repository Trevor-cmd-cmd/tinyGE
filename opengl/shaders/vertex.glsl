#version 330 core
layout (location = 0) in vec3 aPos;

uniform vec3 cameraPos;

void main()
{
    vec3 pos = aPos - cameraPos;

    gl_Position = vec4(pos, 1.0);
}
