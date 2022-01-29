/**
 * @file Cube.hpp
 * @author Przemysław Cedro, Przemysław Ciesek, Kamil Adaś
 * @version 1.0
 * @date 2022-01-28
 */

#pragma once

#include "Mesh.hpp"

#include <GL/glew.h>
#include <glm/glm.hpp>

/**
 * @brief Klasa przechowująca dane geometryczne sześcianu
 */
class Cube : public IMesh
{
public:
    /**
     * @brief Ilość wierzchołków w tablicy wierzchołków sześcianu
     */
    const size_t VERT_COUNT = 24;
    /**
     * @brief Ilość indeksów w tablicy indeksów sześcianu
     */
    const size_t INDEX_COUNT = 36;

    float *vertices;

public:
    /**
     * @brief Konstruktor
     * 
     * @param size_side długość boku sześcianu
     */
    Cube( float size_side );
    /**
     * @brief Destruktor
     */
    ~Cube();

    /**
     * @brief Zwraca wskaźnik na pozycje wierzchołków sześcianu
     * 
     * @return wskaźnik na pozycje wierzchołków sześcianu
     */
    const float *get_vertices() const override;
    /**
     * @brief Zwraca wskaźnik na indeksy wierzchołków sześcianu
     * 
     * @return wskaźnik na indeksy wierzchołków sześcianu
     */
    const unsigned int *get_indices() const override;
    /**
     * @brief Zwraca ilość indeksów dla wierzchołków sześcianu
     * 
     * @return ilość indeksów dla wierzchołków sześcianu
     */
    const unsigned int get_index_count() const override;

    /**
     * @brief Zwraca wskaźnik na wektory normalne sześcianu
     * 
     * @return wskaźnik na wektory normalne sześcianu
     */
    const float *get_normals() const override;
};