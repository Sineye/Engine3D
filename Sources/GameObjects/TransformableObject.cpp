#include "TransformableObject.hpp"

#include "../Engine/Engine.hpp"

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
    auto& cam = Engine::get_instance()->get_camera();

    glMatrixMode( GL_MODELVIEW );
	glm::mat4 m = cam.view_matrix *  glm::translate( translation ) * rotation;
	glLoadMatrixf( glm::value_ptr(m) );
}
