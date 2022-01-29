/**
 * @file FirstCubeTestObject.hpp
 * @author Przemysław Cedro, Przemysław Ciesek, Kamil Adaś
 * @version 1.0
 * @date 2022-01-28
 */

#pragma once

#include "../GameObjects/DrawableObject.hpp"
#include "../GameObjects/EventListeningObject.hpp"
#include "../GameObjects/UpdatableObject.hpp"

/**
 * @brief Klasa do testowania renderowania prostych sześcianów
 */
class FirstCubeTestObject : virtual public DrawableObject, virtual public EventListeningObject, virtual public UpdatableObject
{
public:
    /**
     * @brief Metoda wywoływana przy każdej klatce gry
     * 
     * @param dt czas od ostatniej klatki w ms
     */
    void update( uint32_t dt ) override;
    /**
     * @brief Metoda obsługująca wejście z klawiatury
     * 
     * @param e zdarzenie
     */
    void handle_event( const SDL_Event& e ) override;
    /**
     * @brief Metoda wywoływana w kroku rysowania
     */
    void draw() override;
};