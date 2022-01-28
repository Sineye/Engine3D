#pragma once

#include "Cube.hpp"

class ColoredCube : public Cube
{
private:
    float *colors;

public:
    ColoredCube( float size_side, glm::vec3 color );
    ~ColoredCube();

    const float *get_colors() const override;
};