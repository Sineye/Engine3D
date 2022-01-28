#include "FirstCubeTestObject.hpp"

#include <SDL_opengl.h>
#include <glm/ext.hpp>

static const GLfloat vertices[] = {
//   x      y      z      r     g     b
    -0.5f, -0.5f, -0.5f,  1.f, 0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.f, 0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.f, 0.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  1.f, 0.0f, 0.0f,

    -0.5f,  0.5f, -0.5f,  1.f, 0.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.f, 0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.f, 0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.f, 0.0f, 0.0f,
};

static const GLubyte indices[] {
    0, 1, 2, 2, 3, 0, // lower face
    0, 7, 4, 0, 3, 7, // left face
    0, 4, 5, 0, 5, 1, // back face
    1, 5, 6, 1, 6, 2, // right face
    2, 6, 7, 2, 7, 3, // front face
    4, 7, 6, 4, 6, 5  // top face 
};

void FirstCubeTestObject::update( uint32_t dt ) 
{

}

void FirstCubeTestObject::draw() 
{
    glEnableClientState( GL_VERTEX_ARRAY );
    glEnableClientState( GL_COLOR_ARRAY );
        glVertexPointer( 3, GL_FLOAT, 6 * sizeof( GLfloat ), vertices );
        glColorPointer( 3, GL_FLOAT, 6 * sizeof( GLfloat ), vertices + 3 );

        glDrawElements( GL_TRIANGLES, sizeof( indices ), GL_UNSIGNED_BYTE, indices );
    glDisableClientState( GL_VERTEX_ARRAY );
    glDisableClientState( GL_COLOR_ARRAY );
}

void FirstCubeTestObject::handle_event( const SDL_Event& e ) 
{

}
