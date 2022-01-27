#pragma once

#include "../PrimitiveRendering/Mesh.hpp"
#include "TransformableObject.hpp"
#include "DrawableObject.hpp"

class MeshObject :  virtual public TransformableObject,
                    virtual public DrawableObject
{
private:
    IMesh *mesh;

public:
    // MeshObject class takes ownership over the pointer
    MeshObject( IMesh *mesh );

    void draw() override;
};