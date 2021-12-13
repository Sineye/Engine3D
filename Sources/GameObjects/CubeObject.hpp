#pragma once

#include "../PrimitiveRendering/Cube.hpp"
#include "../GameObjects/DrawableObject.hpp"

class CubeObject : public Cube, virtual public DrawableObject
{
public:
    CubeObject( float size_side, glm::vec3 color );
    void draw() override;
};