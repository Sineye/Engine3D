#include "TexturedCubeObject.hpp"

TexturedCubeObject::TexturedCubeObject(float size_side, const char *img_path) : TexturedCube( size_side, img_path )
{

}

void TexturedCubeObject::draw() 
{
    load_transformation();

    if( texture )
    {
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
        glBindTexture( GL_TEXTURE_2D, texture->get_id() );
            glVertexPointer(3, GL_FLOAT, 0, vertices);
            glTexCoordPointer(2, GL_FLOAT, 0, tex_coords);
            glNormalPointer(GL_FLOAT, 0, normals);

            glDrawElements(GL_TRIANGLES, sizeof(unsigned char) * INDEX_COUNT, GL_UNSIGNED_BYTE, indices);
        glBindTexture( GL_TEXTURE_2D, 0 );
        glDisableClientState(GL_NORMAL_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);
    }
}
