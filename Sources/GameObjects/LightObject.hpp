#pragma once

#include "TransformableObject.hpp"
#include "DrawableObject.hpp"

#include <GL/glew.h>
#include <glm/glm.hpp>

class LightObject : virtual public TransformableObject,
                    virtual public DrawableObject
{
public:
    GLenum light_num;

    glm::vec4 ambient;
    glm::vec4 diffuse;
    glm::vec4 specular;


public:
    LightObject( GLenum light_num );

    void enable();
    void update_attributes();

    void draw() override;
};