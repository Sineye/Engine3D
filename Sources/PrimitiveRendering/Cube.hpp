#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

struct Cube
{
public:
    const size_t VERT_COUNT = 24;
    const size_t INDEX_COUNT = 36;

    float *vertices;
    float *colors;

    const unsigned char *indices;
    const float *normals;

public:
    Cube( float size_side, glm::vec3 color );
    ~Cube();
};