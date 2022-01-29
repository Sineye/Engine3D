/**
 * @file SimpleDrawableObject.hpp
 * @author Przemysław Cedro, Przemysław Ciesek, Kamil Adaś
 * @version 1.0
 * @date 2022-01-28
 */

#pragma once

#include "DrawableObject.hpp"

#include <functional>

/**
 * @brief Klasa mająca wykonywać prostą operację rysowania na ekran
 */
class SimpleDrawableObject : public DrawableObject
{
private:
    /**
     * @brief Funkcja wywoływana przez klasę
     */
    std::function< void() > draw_func;

public:
    /**
     * @brief Konstruktor
     * 
     * @param draw_func funkcja lambda mająca wykonywać prostą operację rysowania na ekran
     */
    SimpleDrawableObject( std::function< void() > draw_func );

    /**
     * @brief Metoda wywoływana na etapie rysowania klatki przez silnik
     */
    void draw() override;
};