#ifndef __TRANSFORMABLEOBJECT_H__
#define __TRANSFORMABLEOBJECT_H__

#include "GameObject.hpp"

#include <glm/glm.hpp>

class TransformableObject : virtual public GameObject
{
public:
    glm::vec3 translation;
    // glm::vec4 scale;
    glm::mat4 rotation; // rotation as matrix, because it can be done in various orders

public:
    TransformableObject();

    void load_transformation();
};

#endif // __TRANSFORMABLEOBJECT_H__