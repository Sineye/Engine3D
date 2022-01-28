#include "MeshObject.hpp"

MeshObject::MeshObject( IMesh *mesh ) 
{
    this->mesh = mesh;
}

void MeshObject::draw() 
{
    load_transformation();


    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, mesh->get_vertices() );

    if( mesh->get_colors() )
    {
        glEnableClientState(GL_COLOR_ARRAY);
        glColorPointer(3, GL_FLOAT, 0, mesh->get_colors());
    }
    if( mesh->get_normals() )
    {
        glEnableClientState(GL_NORMAL_ARRAY);
        glNormalPointer(GL_FLOAT, 0, mesh->get_normals());
    }
    if( mesh->get_tex_coords() )
    {
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glBindTexture( GL_TEXTURE_2D, mesh->get_texture_id() );
        glTexCoordPointer(2, GL_FLOAT, 0, mesh->get_tex_coords());
    }

    glDrawElements(GL_TRIANGLES, mesh->get_index_count(), GL_UNSIGNED_INT, mesh->get_indices());

    glBindTexture( GL_TEXTURE_2D, 0 );
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}
