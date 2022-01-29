/**
 * @file PrimitiveRenderer.hpp
 * @author Przemysław Cedro, Przemysław Ciesek, Kamil Adaś
 * @version 1.0
 * @date 2022-01-28
 */

#pragma once

#include "../Utility/ColoredVertex.hpp"

#include <vector>

/**
 * @brief Klasa służąca do rysowania prymitywów
 */
class PrimitiveRenderer
{
public:
    /**
     * @brief Rysuje punkty na ekranie
     * 
     * @param points wektor pozycji punktów
     * @param color kolor punktów
     * @param point_size wielkość punktu
     */
    static void draw_points( const std::vector<glm::vec3>& points, glm::vec3 color, float point_size = 1 );
    /**
     * @brief Rysuje punkty na ekranie
     * 
     * @param vertices wektor struktur z pozycjami i kolorami punktów
     * @param point_size wielkośc punktów
     */
    static void draw_points( const std::vector<ColoredVertex>& vertices, float point_size = 1 );
    /**
     * @brief Rysuje linie na ekranie
     * 
     * @param lines wektor pozycji wierzchołków, z których składają się linie
     * @param color kolor linii
     * @param line_width grubość linii
     */
    static void draw_lines( const std::vector<glm::vec3>& lines, glm::vec3 color, float line_width = 1 );
    /**
     * @brief Rysuje linie na ekranie
     * 
     * @param lines wektor struktur z pozycjami i kolorami wierzchołków, z których składają się linie
     * @param line_width grubość linii
     */
    static void draw_lines( const std::vector<ColoredVertex>& lines, float line_width = 1 );
    /**
     * @brief Rysuje przerywaną linię
     * 
     * @param points punkty, z których składa się linia
     * @param color kolor linii
     * @param line_width grubość linii
     */
    static void draw_multiline( const std::vector<glm::vec3>& points, glm::vec3 color, float line_width = 1 );
    /**
     * @brief Rysuje przerywaną linię
     * 
     * @param points punkty struktur z pozycjami i kolorami wierzchołków, z których składa się linia
     * @param line_width grubość linii
     */
    static void draw_multiline( const std::vector<ColoredVertex>& points, float line_width = 1 );
    /**
     * @brief Rysuje trójkąt
     * 
     * @param p1 1. wierzchołek trójkąta
     * @param p2 2. wierzchołek trójkąta
     * @param p3 3. wierzchołek trójkąta
     * @param color kolor trójkąta
     */
    static void draw_triangle( glm::vec3 p1, glm::vec3 p2, glm::vec3 p3, glm::vec3 color );
    /**
     * @brief Rysuje trójkąt
     * 
     * @param p1 1. kolorowy wierzchołek trójkąta 
     * @param p2 2. kolorowy wierzchołek trójkąta 
     * @param p3 3. kolorowy wierzchołek trójkąta 
     */
    static void draw_triangle( ColoredVertex p1, ColoredVertex p2, ColoredVertex p3 );
    /**
     * @brief Rysuje wachlarz trójkątów
     * 
     * @param fan_vertices wierzchołki trójkątów
     * @param color kolor trójkątów
     */
    static void draw_triangle_fan( const std::vector<glm::vec3>& fan_vertices, glm::vec3 color );
    /**
     * @brief Rysuje czworokąt
     * 
     * @param p1 1. wierzchołek czworokąta
     * @param p2 2. wierzchołek czworokąta
     * @param p3 3. wierzchołek czworokąta
     * @param p4 4. wierzchołek czworokąta
     * @param color kolor czworokąta 
     */
    static void draw_quad( glm::vec3 p1, glm::vec3 p2, glm::vec3 p3, glm::vec3 p4, glm::vec3 color );
    /**
     * @brief Rysuje czworokąt
     * 
     * @param p1 1. kolorowy wierzchołek czworokąta
     * @param p2 2. kolorowy wierzchołek czworokąta
     * @param p3 3. kolorowy wierzchołek czworokąta
     * @param p4 4. kolorowy wierzchołek czworokąta
     */
    static void draw_quad( ColoredVertex p1, ColoredVertex p2, ColoredVertex p3, ColoredVertex p4 );
};