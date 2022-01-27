#pragma once

#include "Cube.hpp"
#include "../Texture/Texture.hpp"

class TexturedCube : public Cube
{
public:
    Texture *texture;

public:
    TexturedCube( float size_side, const char *img_path );
    ~TexturedCube();

    const float *get_tex_coords() const override;
    const GLuint get_texture_id() const override;
};