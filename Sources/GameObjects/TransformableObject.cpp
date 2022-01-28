#include "TransformableObject.hpp"

#include "../Engine/Engine.hpp"

#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>

TransformableObject::TransformableObject() 
{
    translation = { 0.f, 0.f, 0.f };
    scale = { 1.f, 1.f, 1.f };
    rotation = glm::mat4(1.f);
}

glm::mat4 TransformableObject::get_transformation() const
{
    auto& cam = Engine::get_instance()->get_camera();

    return cam.get_view_matrix() * glm::translate( translation ) * rotation * glm::scale( scale );
}

void TransformableObject::load_transformation() 
{
    glMatrixMode( GL_MODELVIEW );
	glLoadMatrixf( glm::value_ptr( get_transformation() ) );
}
