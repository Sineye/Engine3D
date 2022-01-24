#include "TexturedCube.hpp"

#include "../ResourceManager/ResourceManager.hpp"

const float cube_texc[] = {
	0.0f, 0.0f,		1.0f, 0.0f,		0.0f, 1.0f,		1.0f, 1.0f,
	1.0f, 0.0f,		1.0f, 1.0f,		0.0f, 0.0f,		0.0f, 1.0f,
	1.0f, 0.0f,		1.0f, 1.0f,		0.0f, 0.0f,		0.0f, 1.0f,
	0.0f, 0.0f,		1.0f, 0.0f,		0.0f, 1.0f,		1.0f, 1.0f,
	1.0f, 0.0f,		1.0f, 1.0f,		0.0f, 0.0f,		0.0f, 1.0f,
	0.0f, 0.0f,		1.0f, 0.0f,		0.0f, 1.0f,		1.0f, 1.0f
};


TexturedCube::TexturedCube( float size_side, const char *img_path ) : Cube( size_side, glm::vec3() ) 
{
    tex_coords = cube_texc;
	texture = ResourceManager::load_texture( img_path );
}
