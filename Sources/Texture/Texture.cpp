#include "Texture.hpp"

#include "../External/stb_image.h"

Texture::Texture() 
{
    id = 0;
    size = {0, 0};
    format = 0;
}

Texture::~Texture() 
{
    if( id != 0 )
    {
        glDeleteTextures( 1, &id );
    }
}

bool Texture::load( const char *path ) 
{
    int channel_count;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load( path, &size.x, &size.y, &channel_count, 0 );

    if( data )
    {
        switch( channel_count )
        {
            case 1:
                format = GL_RED;
                break;
            case 2:
                format = GL_RG;
                break;
            case 3:
                format = GL_RGB;
                break;
            case 4:
                format = GL_RGBA;
                break;
            default:
                format = GL_RGB;
        }

        glGenTextures( 1, &id );
        glBindTexture( GL_TEXTURE_2D, id );
        glTexImage2D( GL_TEXTURE_2D, 0, format, size.x, size.y, 0, format, GL_UNSIGNED_BYTE, data );

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free( data );
        glBindTexture( GL_TEXTURE_2D, 0 );

        return true;
    }

    return false;
}

GLuint Texture::get_id() const
{
    return id;
}

glm::ivec2 Texture::get_size() const
{
    return size;
}

GLenum Texture::get_format() const
{
    return format;
}
