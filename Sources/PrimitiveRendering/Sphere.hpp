/**
 * @file Sphere.hpp
 * @author Przemysław Cedro, Przemysław Ciesek, Kamil Adaś
 * @version 1.0
 * @date 2022-01-28
 */

#pragma once

#include "Mesh.hpp"

#include <glm/glm.hpp>

#include <vector>

/**
 * @brief Klasa przechowująca dane o sferze
 * 
 */
class Sphere : public IMesh
{
private:
    /**
     * @brief Wektor pozycji wierzchołków sfery
     */
    std::vector<float> vec_vertices;
    /**
     * @brief Wektor indeksów wierzchołków sfery
     */
    std::vector<unsigned int> vec_indices;
    /**
     * @brief Wektor wektorów normalnych sfery
     */
    std::vector<float> vec_normals;
    /**
     * @brief Wektor kolorów wierzchołków sfery
     */
    std::vector<float> vec_colors;


public:
    /**
     * @brief Konstruktor
     * 
     * @param radius promień sfery
     * @param sector_count ilość segmentów wzdłuż równika sfery
     * @param stack_count ilość segmentów między biegunami sfery
     * @param color kolor sfery
     */
    Sphere( float radius, int sector_count, int stack_count, glm::vec3 color );

    /**
     * @brief Zwraca wskaźnik na pozycje wierzchołków sfery
     * 
     * @return wskaźnik na pozycje wierzchołków sfery
     */
    const float *get_vertices() const override;
    /**
     * @brief Zwraca wskaźnik na indeksy wierzchołków sfery
     * 
     * @return wskaźnik na indeksy wierzchołków sfery
     */
    const unsigned int *get_indices() const override;
    /**
     * @brief Zwraca ilość indeksów dla wierzchołków sfery
     * 
     * @return ilość indeksów dla wierzchołków sfery
     */
    const unsigned int get_index_count() const override;

    /**
     * @brief Zwraca wskaźnik na kolory wierzchołków sfery
     * 
     * @return wskaźnik na kolory wierzchołków sfery
     */
    const float *get_colors() const override;

    /**
     * @brief Zwraca wskaźnik na wektory normalne sfery
     * 
     * @return wskaźnik na wektory normalne sfery
     */
    const float *get_normals() const override;
};