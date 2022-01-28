#include "Cube.hpp"

const float cube_vert[] = {
	-1.0f, -1.0f,  1.0f,	 1.0f, -1.0f,  1.0f,	-1.0f,  1.0f,  1.0f,	 1.0f,  1.0f,  1.0f,
	-1.0f, -1.0f, -1.0f,	-1.0f,  1.0f, -1.0f,	 1.0f, -1.0f, -1.0f,	 1.0f,  1.0f, -1.0f,
	-1.0f,  1.0f, -1.0f,	-1.0f,  1.0f,  1.0f,	 1.0f,  1.0f, -1.0f,	 1.0f,  1.0f,  1.0f,
	-1.0f, -1.0f, -1.0f,	 1.0f, -1.0f, -1.0f,	-1.0f, -1.0f,  1.0f,	 1.0f, -1.0f,  1.0f,
	 1.0f, -1.0f, -1.0f,	 1.0f,  1.0f, -1.0f,	 1.0f, -1.0f,  1.0f,	 1.0f,  1.0f,  1.0f,
	-1.0f, -1.0f, -1.0f,	-1.0f, -1.0f,  1.0f,	-1.0f,  1.0f, -1.0f,	-1.0f,  1.0f,  1.0f,
};

const unsigned int cube_ind[] = {
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
	 0.0f,  0.0f,  1.0f,	 0.0f,  0.0f,  1.0f,	 0.0f,  0.0f,  1.0f,	 0.0f,  0.0f,  1.0f,
	 0.0f,  0.0f, -1.0f,	 0.0f,  0.0f, -1.0f,	 0.0f,  0.0f, -1.0f,	 0.0f,  0.0f, -1.0f,
	 0.0f,  1.0f,  0.0f,	 0.0f,  1.0f,  0.0f,	 0.0f,  1.0f,  0.0f,	 0.0f,  1.0f,  0.0f,
	 0.0f, -1.0f,  0.0f,	 0.0f, -1.0f,  0.0f,	 0.0f, -1.0f,  0.0f,	 0.0f, -1.0f,  0.0f,
	 1.0f,  0.0f,  0.0f,	 1.0f,  0.0f,  0.0f,	 1.0f,  0.0f,  0.0f,	 1.0f,  0.0f,  0.0f,
	-1.0f,  0.0f,  0.0f,	-1.0f,  0.0f,  0.0f,	-1.0f,  0.0f,  0.0f,	-1.0f,  0.0f,  0.0f
};

Cube::Cube( float size_side ) 
{
    vertices = new float[VERT_COUNT * 3];
    
    for (size_t i = 0; i < VERT_COUNT * 3; i++)
    {
        vertices[i] = cube_vert[i] * size_side / 2.f; // divide by 2 because by default sides are 2 in length
    }
}

Cube::~Cube() 
{
    delete[] vertices;
}

const float* Cube::get_vertices() const 
{
	return vertices;
}

const unsigned int* Cube::get_indices() const 
{
	return cube_ind;
}

const float* Cube::get_normals() const 
{
	return cube_norm;
}

const unsigned int Cube::get_index_count() const
{
	return INDEX_COUNT;
}