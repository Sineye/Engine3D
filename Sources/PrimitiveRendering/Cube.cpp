#include "Cube.hpp"

#include <cstring>

static const size_t VERT_COUNT = 8;
static const size_t COLOR_COUNT = 8;
static const size_t INDEX_COUNT = 3 * 2 * 6;

static const glm::vec3 cube_vertices_base[VERT_COUNT] = {
    glm::vec3( -1.f, -1.f, -1.f ), 
    glm::vec3(  1.f, -1.f, -1.f ), 
    glm::vec3(  1.f, -1.f,  1.f ), 
    glm::vec3( -1.f, -1.f,  1.f ), 

    glm::vec3( -1.f,  1.f, -1.f ),
    glm::vec3(  1.f,  1.f, -1.f ),
    glm::vec3(  1.f,  1.f,  1.f ),
    glm::vec3( -1.f,  1.f,  1.f )
};

static const GLuint cube_indices[INDEX_COUNT] = {
    0, 1, 2, 2, 3, 0, // lower face
    0, 7, 4, 0, 3, 7, // left face
    0, 4, 5, 0, 5, 1, // back face
    1, 5, 6, 1, 6, 2, // right face
    2, 6, 7, 2, 7, 3, // front face
    4, 7, 6, 4, 6, 5  // top face 
};

Cube::Cube( GLfloat size_side, glm::vec3 color ) 
{
    vertices = new glm::vec3[VERT_COUNT];
    colors = new glm::vec3[COLOR_COUNT];
    indices = new GLuint[INDEX_COUNT];

    for (size_t i = 0; i < VERT_COUNT; i++)
    {
        vertices[i] *= size_side / 2.f;
    }
    for (size_t i = 0; i < COLOR_COUNT; i++)
    {
        colors[i] = color;
    }
    
    std::memcpy( indices, cube_indices, INDEX_COUNT * sizeof(GLuint) );
}

Cube::~Cube() 
{
    delete vertices;
    delete colors;
    delete indices;
}
