/**
 * @file TransformableObject.hpp
 * @author Przemysław Cedro, Przemysław Ciesek, Kamil Adaś
 * @version 1.0
 * @date 2022-01-28
 */

#ifndef __TRANSFORMABLEOBJECT_H__
#define __TRANSFORMABLEOBJECT_H__

#include "GameObject.hpp"

#include <glm/glm.hpp>

/**
 * @brief Klasa przechowująca informacje o podstawowych danych transformacji obiektu
 */
class TransformableObject : virtual public GameObject
{
public:
    /**
     * @brief Translacja obiektu w przestrzeni
     */
    glm::vec3 translation;
    /**
     * @brief Skala obiektu
     */
    glm::vec3 scale;
    /**
     * @brief Macierz wynikowa obrotu obiektu
     */
    glm::mat4 rotation; // rotation as matrix, because it can be done in various orders

public:
    /**
     * @brief Konstruktor
     */
    TransformableObject();

    /**
     * @brief Zwraca wynikową macierz transformacji dla obiektu
     * 
     * @return macierz transformacji obiektu
     */
    glm::mat4 get_transformation() const;
    /**
     * @brief Ładuje transformację obiektu jako aktualną transformację dla macierzy Model-View OpenGL
     */
    void load_transformation();
};

#endif // __TRANSFORMABLEOBJECT_H__