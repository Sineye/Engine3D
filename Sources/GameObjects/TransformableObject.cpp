#include "TransformableObject.hpp"

#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>

TransformableObject::TransformableObject() 
{
    translation = { 0.f, 0.f, 0.f };
    // scale = { 1.f, 1.f, 1.f, 1.f };
    rotation = glm::mat4(1.f);
}

void TransformableObject::load_transformation() 
{
    glMatrixMode( GL_MODELVIEW );
	glm::mat4 m = glm::translate( translation ) * rotation;
	glLoadMatrixf( glm::value_ptr(m) );
}
