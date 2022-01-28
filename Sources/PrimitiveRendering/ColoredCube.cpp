#include "ColoredCube.hpp"

ColoredCube::ColoredCube( float size_side, glm::vec3 color ) : Cube( size_side ) 
{
    colors = new float[VERT_COUNT * 3];

    for (size_t i = 0; i < VERT_COUNT * 3; i+=3)
    {
        colors[i+0] = color.r;
        colors[i+1] = color.g;
        colors[i+2] = color.b;
    }
}

ColoredCube::~ColoredCube() 
{
    delete[] colors;
}

const float* ColoredCube::get_colors() const 
{
    return colors;
}
