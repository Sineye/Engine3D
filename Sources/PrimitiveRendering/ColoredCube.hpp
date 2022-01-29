/**
 * @file ColoredCube.hpp
 * @author Przemysław Cedro, Przemysław Ciesek, Kamil Adaś
 * @version 1.0
 * @date 2022-01-28
 */

#pragma once

#include "Cube.hpp"

/**
 * @brief Klasa przechowująca dane kolorowego sześcianu
 * 
 */
class ColoredCube : public Cube
{
private:
    /**
     * @brief Wskaźnik na tablicę kolorów
     */
    float *colors;

public:
    /**
     * @brief Konstruktor
     * 
     * @param size_side długość boku sześcianu
     * @param color kolor sześcianu
     */
    ColoredCube( float size_side, glm::vec3 color );
    /**
     * @brief Destruktor
     */
    ~ColoredCube();

    /**
     * @brief Zwraca wskaźnik na kolory wierzchołków sześcianu
     * 
     * @return wskaźnik na kolory wierzchołków sześcianu
     */
    const float *get_colors() const override;
};