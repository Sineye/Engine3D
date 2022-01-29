/**
 * @file LightingTest.hpp
 * @author Przemysław Cedro, Przemysław Ciesek, Kamil Adaś
 * @version 1.0
 * @date 2022-01-28
 */

#pragma once

#include "../GameObjects/UpdatableObject.hpp"
#include "../GameObjects/EventListeningObject.hpp"
#include "../GameObjects/LightObject.hpp"
#include "../GameObjects/MeshObject.hpp"

#include <memory>

/**
 * @brief Klasa do testowania oświetlenia
 */
class LightingTest : virtual public UpdatableObject, virtual public EventListeningObject
{
private:
    /**
     * @brief Kąt obrotu kostki
     */
    float cube_angle;
    /**
     * @brief Wektor 2D z zapisanym wejściem z klawiatury dla kostki:
     * x - obrót,
     * y - skala
     */
    glm::vec2 cube_input; 

    /**
     * @brief Obiekt światła 1.
     */
    std::shared_ptr<LightObject> lightObj;
    /**
     * @brief Obiekt kostki
     */
    std::shared_ptr<MeshObject> cubeObj;

    /**
     * @brief Obiekt sfery
     */
    std::shared_ptr<MeshObject> sphereObj;
    /**
     * @brief Obiekt światła 2.
     */
    std::shared_ptr<LightObject> sphereLight;
    /**
     * @brief Kąt obrotu sfery
     */
    float sphere_angle;

public:
    /**
     * @brief Konstruktor; tworzy obiekty i przekazuje je silnikowi
     */
    LightingTest();

    /**
     * @brief Funcja wykonywana przy każdej klatce gry
     * 
     * @param dt czas od ostatniej klatki w ms
     */
    void update( uint32_t dt ) override;
    /**
     * @brief Funkcja obsługująca wejście z klawiatury i myszki
     * 
     * @param e zdarzenie
     */
    void handle_event( const SDL_Event& e ) override;
};