#include "Cube.hpp"

#include <cstdlib>
#include <cstring>

const float cube_vert[] = {
	-1.0f, -1.0f,  1.0f,	 1.0f, -1.0f,  1.0f,	-1.0f,  1.0f,  1.0f,	 1.0f,  1.0f,  1.0f,
	-1.0f, -1.0f, -1.0f,	-1.0f,  1.0f, -1.0f,	 1.0f, -1.0f, -1.0f,	 1.0f,  1.0f, -1.0f,
	-1.0f,  1.0f, -1.0f,	-1.0f,  1.0f,  1.0f,	 1.0f,  1.0f, -1.0f,	 1.0f,  1.0f,  1.0f,
	-1.0f, -1.0f, -1.0f,	 1.0f, -1.0f, -1.0f,	-1.0f, -1.0f,  1.0f,	 1.0f, -1.0f,  1.0f,
	 1.0f, -1.0f, -1.0f,	 1.0f,  1.0f, -1.0f,	 1.0f, -1.0f,  1.0f,	 1.0f,  1.0f,  1.0f,
	-1.0f, -1.0f, -1.0f,	-1.0f, -1.0f,  1.0f,	-1.0f,  1.0f, -1.0f,	-1.0f,  1.0f,  1.0f,
};

const unsigned char cube_ind[] = {
	0,  1,  2,    
	2,  1,  3,

	4,  5,  6,    
	6,  5,  7,

	8,  9,  10,    
	10, 9,  11,

	12, 13, 14,    
	14, 13, 15,

	16, 17, 18,    
	18, 17, 19,

	20, 21, 22,    
	22, 21, 23
};

const float cube_norm[] = {
	 0.0f, 0.0f, 1.0f,	 0.0f, 0.0f, 1.0f,	 0.0f, 0.0f, 1.0f,	 0.0f, 0.0f, 1.0f,
	 0.0f, 0.0f,-1.0f,	 0.0f, 0.0f,-1.0f,	 0.0f, 0.0f,-1.0f,	 0.0f, 0.0f,-1.0f,
	 0.0f, 1.0f, 0.0f,	 0.0f, 1.0f, 0.0f,	 0.0f, 1.0f, 0.0f,	 0.0f, 1.0f, 0.0f,
	 0.0f,-1.0f, 0.0f,	 0.0f,-1.0f, 0.0f,	 0.0f,-1.0f, 0.0f,	 0.0f,-1.0f, 0.0f,
	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f,	-1.0f, 0.0f, 0.0f,	-1.0f, 0.0f, 0.0f,	-1.0f, 0.0f, 0.0f
};

Cube::Cube( GLfloat size_side, glm::vec3 color ) 
{
    vertices = new float[VERT_COUNT];
    
    for (size_t i = 0; i < VERT_COUNT; i++)
    {
        vertices[i] = cube_vert[i] * size_side / 2.f;
    }

    colors = new float[VERT_COUNT];

    for (size_t i = 0; i < VERT_COUNT; i+=3)
    {
        colors[i+0] = color.r;
        colors[i+1] = color.g;
        colors[i+2] = color.b;
    }
    
    indices = cube_ind;
    normals = cube_norm;
}

Cube::~Cube() 
{
    delete[] vertices;
    delete[] colors;
}
