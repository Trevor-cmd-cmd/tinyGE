#pragma once

struct Vector3 {
    float x, y, z;

    Vector3(float x, float y, float z)
        : x((2.0f / 16.0f) * x), y((2.0f / 9.0f) * y), z(0 * z)
    {}

    Vector3& operator+=(const Vector3& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;

        return *this;
    }
};