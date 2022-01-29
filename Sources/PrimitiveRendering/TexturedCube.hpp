/**
 * @file TexturedCube.hpp
 * @author Przemysław Cedro, Przemysław Ciesek, Kamil Adaś
 * @version 1.0
 * @date 2022-01-28
 */

#pragma once

#include "Cube.hpp"
#include "../Texture/Texture.hpp"

/**
 * @brief Klasa przechowująca dane oteksturowanego sześcianu
 * 
 */
class TexturedCube : public Cube
{
public:
    /**
     * @brief Tekstura sześcianu
     */
    Texture *texture;

public:
    /**
     * @brief Konstruktor
     * 
     * @param size_side długość boku sześcianu
     * @param img_path ścieżka do pliku tekstury
     */
    TexturedCube( float size_side, const char *img_path );
    /**
     * @brief Destruktor
     * 
     */
    ~TexturedCube();

    /**
     * @brief Zwraca wskaźnik na koordynaty teksturowe dla wierzchołków sześcianu
     * 
     * @return wskaźnik na koordynaty teksturowe dla wierzchołków sześcianu
     */
    const float *get_tex_coords() const override;
    /**
     * @brief Zwraca ID tekstury przypisanej do sześcianu
     * 
     * @return ID tekstury przypisanej do sześcianu
     */
    const GLuint get_texture_id() const override;
};