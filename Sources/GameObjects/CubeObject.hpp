#pragma once

#include "../PrimitiveRendering/Cube.hpp"
#include "../GameObjects/TransformableObject.hpp"
#include "../GameObjects/DrawableObject.hpp"

class CubeObject : virtual public Cube, 
                   virtual public TransformableObject,
                   virtual public DrawableObject
{
public:
    CubeObject( float size_side, glm::vec3 color );
    void draw() override;
};