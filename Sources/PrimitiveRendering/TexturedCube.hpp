#pragma once

#include "Cube.hpp"
#include "../Texture/Texture.hpp"

class TexturedCube : public Cube
{
public:
    const float *tex_coords;
    Texture *texture;

public:
    TexturedCube( float size_side, const char *img_path );
};