/**
 * @file LightObject.hpp
 * @author Przemysław Cedro, Przemysław Ciesek, Kamil Adaś
 * @version 1.0
 * @date 2022-01-28
 */

#pragma once

#include "TransformableObject.hpp"
#include "DrawableObject.hpp"

#include <GL/glew.h>
#include <glm/glm.hpp>

/**
 * @brief Klasa światła w przestrzeni
 */
class LightObject : virtual public TransformableObject,
                    virtual public DrawableObject
{
public:
    /**
     * @brief Identyfikator światła
     */
    GLenum light_num;

    /**
     * @brief Współczynnik oświetlenia otoczenia
     */
    glm::vec4 ambient;
    /**
     * @brief Współczynnik rozproszenia światła
     */
    glm::vec4 diffuse;
    /**
     * @brief Współczynnik odblasku światła
     */
    glm::vec4 specular;


public:
    /**
     * @brief Konstruktor
     * 
     * @param light_num identyfikator światła
     */
    LightObject( GLenum light_num );

    /**
     * @brief Ustawia światło w przestrzeni
     */
    void enable();
    /**
     * @brief Aktualizuje atrybuty światła
     */
    void update_attributes();

    /**
     * @brief Renderuje światło
     */
    void draw() override;
};