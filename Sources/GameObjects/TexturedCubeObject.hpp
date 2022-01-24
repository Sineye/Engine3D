#pragma once

#include "../PrimitiveRendering/TexturedCube.hpp"
#include "../GameObjects/TransformableObject.hpp"
#include "../GameObjects/DrawableObject.hpp"

class TexturedCubeObject : virtual public TexturedCube,
                           virtual public TransformableObject,
                           virtual public DrawableObject
{
public:
    TexturedCubeObject( float size_side, const char *img_path );
    void draw() override;
};