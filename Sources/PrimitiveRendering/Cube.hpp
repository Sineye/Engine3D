#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

struct Cube
{
public:
    glm::vec3 *vertices;
    glm::vec3 *colors;
    GLuint *indices;

public:
    Cube( float size_side, glm::vec3 color );
    ~Cube();
};