#ifndef __TRANSFORMABLEOBJECT_H__
#define __TRANSFORMABLEOBJECT_H__

#include "GameObject.hpp"

#include <glm/glm.hpp>

class TransformableObject : virtual public GameObject
{
public:
    glm::vec3 translation;
    glm::vec3 scale;
    glm::mat4 rotation; // rotation as matrix, because it can be done in various orders

public:
    TransformableObject();

    glm::mat4 get_transformation() const;
    void load_transformation();
};

#endif // __TRANSFORMABLEOBJECT_H__