/**
 * @file MeshObject.hpp
 * @author Przemysław Cedro, Przemysław Ciesek, Kamil Adaś
 * @version 1.0
 * @date 2022-01-28
 */

#pragma once

#include "../PrimitiveRendering/Mesh.hpp"
#include "TransformableObject.hpp"
#include "DrawableObject.hpp"

/**
 * @brief Klasa mogąca przechowywać bryły geometryczne i je renderować
 * 
 */
class MeshObject :  virtual public TransformableObject,
                    virtual public DrawableObject
{
private:
    /**
     * @brief Przechowywana bryła
     */
    IMesh *mesh;

public:
    /**
     * @brief Konstruktor
     * 
     * @param mesh bryła, klasa MeshObject staje się właścicielem wskaźnika do niej
     */
    MeshObject( IMesh *mesh );

    /**
     * @brief Metoda renderująca przechowywaną bryłę
     */
    void draw() override;
};