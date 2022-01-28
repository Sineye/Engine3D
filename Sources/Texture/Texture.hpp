#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

class Texture
{
private:
    GLuint id;
    glm::ivec2 size;
    GLenum format;

public:
    Texture();
    ~Texture();

    bool load( const char *path );

    GLuint get_id() const;
    glm::ivec2 get_size() const;
    GLenum get_format() const;
};