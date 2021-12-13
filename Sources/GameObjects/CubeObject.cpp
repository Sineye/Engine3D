#include "CubeObject.hpp"

CubeObject::CubeObject(float size_side, glm::vec3 color) : Cube(size_side, color) 
{

}

void CubeObject::draw() 
{
    glEnableClientState( GL_VERTEX_ARRAY );
    glEnableClientState( GL_COLOR_ARRAY );
        glVertexPointer( 3, GL_FLOAT, 0, vertices );
        glColorPointer( 3, GL_FLOAT, 0, colors );

        glDrawElements( GL_TRIANGLES, 36, GL_UNSIGNED_INT, indices );
    glDisableClientState( GL_VERTEX_ARRAY );
    glDisableClientState( GL_COLOR_ARRAY );
}
