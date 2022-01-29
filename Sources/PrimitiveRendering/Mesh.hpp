/**
 * @file Mesh.hpp
 * @author Przemysław Cedro, Przemysław Ciesek, Kamil Adaś
 * @version 1.0
 * @date 2022-01-28
 */

#pragma once

#include <GL/glew.h>

/**
 * @brief Interfejs dla brył geometrycznych
 */
class IMesh
{
public:
    /**
     * @brief Zwraca wskaźnik na pozycje wierzchołków bryły
     * 
     * @return wskaźnik na pozycje wierzchołków bryły
     */
    virtual const float *get_vertices() const = 0;
    /**
     * @brief Zwraca wskaźnik na indeksy wierzchołków bryły
     * 
     * @return wskaźnik na indeksy wierzchołków bryły
     */
    virtual const unsigned int *get_indices() const = 0;
    /**
     * @brief Zwraca ilość indeksów dla wierzchołków bryły
     * 
     * @return ilość indeksów dla wierzchołków bryły
     */
    virtual const unsigned int get_index_count() const = 0;

    /**
     * @brief Zwraca wskaźnik na kolory wierzchołków bryły
     * 
     * @return wskaźnik na kolory wierzchołków bryły
     */
    virtual const float *get_colors() const;

    /**
     * @brief Zwraca wskaźnik na wektory normalne bryły
     * 
     * @return wskaźnik na wektory normalne bryły
     */
    virtual const float *get_normals() const;

    /**
     * @brief Zwraca ID tekstury przypisanej do bryły
     * 
     * @return ID tekstury przypisanej do bryły
     */
    virtual const GLuint get_texture_id() const;
    /**
     * @brief Zwraca wskaźnik na koordynaty teksturowe dla wierzchołków bryły
     * 
     * @return wskaźnik na koordynaty teksturowe dla wierzchołków bryły
     */
    virtual const float *get_tex_coords() const;
};