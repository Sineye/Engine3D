/**
 * @file ColoredVertex.hpp
 * @author Przemysław Cedro, Przemysław Ciesek, Kamil Adaś
 * @version 1.0
 * @date 2022-01-28
 */

#pragma once

#include <glm/glm.hpp>

/**
 * @brief Struktura przechowująca dane o kolorowym wierzchołku
 */
struct ColoredVertex
{
    /**
     * @brief Pozycja wierzchołka
     */
    glm::vec2 pos;
    /**
     * @brief Kolor wierzchołka
     */
    glm::vec3 color;
};