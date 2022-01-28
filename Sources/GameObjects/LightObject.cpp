#include "LightObject.hpp"

#include <glm/gtc/type_ptr.hpp>

LightObject::LightObject( GLenum light_num ) 
{
    this->light_num = light_num;
}

void LightObject::enable() 
{
    glEnable( light_num );
}

void LightObject::update_attributes() 
{
    glLightfv(light_num, GL_AMBIENT, glm::value_ptr( ambient ) );
	glLightfv(light_num, GL_DIFFUSE, glm::value_ptr( diffuse ) );
	glLightfv(light_num, GL_SPECULAR, glm::value_ptr( specular ) );
}

void LightObject::draw() 
{
    glm::vec4 v { 0.f, 0.f, 0.f, 1.f };
    v = get_transformation() * v;

    glLightfv( light_num, GL_POSITION, glm::value_ptr(v) );
}
