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


TexturedCube::TexturedCube( float size_side, const char *img_path ) : Cube( size_side ) 
{
	texture = ResourceManager::load_texture( img_path );
}

TexturedCube::~TexturedCube() 
{
	if( texture )
	{
		delete texture;
	}
}

const float* TexturedCube::get_tex_coords() const 
{
	return cube_texc;
}

const GLuint TexturedCube::get_texture_id() const 
{
	if( texture )
	{
		return texture->get_id();
	}

	return 0;
}
