#pragma once

#include "Mesh.hpp"

#include <GL/glew.h>
#include <glm/glm.hpp>

class Cube : public IMesh
{
public:
    const size_t VERT_COUNT = 24;
    const size_t INDEX_COUNT = 36;

    float *vertices;

public:
    Cube( float size_side );
    ~Cube();

    const float *get_vertices() const override;
    const unsigned int *get_indices() const override;
    const unsigned int get_index_count() const override;

    const float *get_normals() const override;
};