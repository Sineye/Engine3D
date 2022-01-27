#pragma once

#include <GL/glew.h>

class IMesh
{
public:
    virtual const float *get_vertices() const = 0;
    virtual const unsigned int *get_indices() const = 0;
    virtual const unsigned int get_index_count() const = 0;

    virtual const float *get_colors() const;

    virtual const float *get_normals() const;

    virtual const GLuint get_texture_id() const;
    virtual const float *get_tex_coords() const;
};