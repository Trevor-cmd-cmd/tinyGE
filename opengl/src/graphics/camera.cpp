#include "camera.h"



Camera::Camera(Vector3 pos)
    : position(pos) { }

void Camera::UpdateCamera(Vector3 pos, const char* name, unsigned int shaderProgram)
{
    position.x = pos.x;
    position.y = pos.y;
    position.z = pos.z;
    GLint location = glGetUniformLocation(shaderProgram, name);
    glUniform3f(location, pos.x, pos.y, pos.z);
}
