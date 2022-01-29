/**
 * @file CameraController.hpp
 * @author Przemysław Cedro, Przemysław Ciesek, Kamil Adaś
 * @version 1.0
 * @date 2022-01-28
 */

#pragma once

#include "EventListeningObject.hpp"
#include "UpdatableObject.hpp"

#include <glm/glm.hpp>

/**
 * @brief Klasa kontrolera dla kamery
 */
class CameraController : virtual public EventListeningObject,
                         virtual public UpdatableObject
{
private:
    /**
     * @brief Flaga wskazująca, czy kontroler jest aktywny
     * 
     */
    bool is_controller_active;

    /**
     * @brief Wektor z danymi o wejściu z klawiaury dla ruchu kamery:
     * x - dla ruchu lewo/prawo,
     * y - dla ruchu przód/tył
     */
    glm::vec2 input_move; 
    /**
     * @brief Wektor z danymi o wejściu z myszy dla obrotu kamery:
     * x - dla odchylenia lewo/prawo,
     * y - dla obrotu góra/dół
     */
    glm::vec2 input_rotation;


public:
    /**
     * @brief Konstruktor
     */
    CameraController();

    /**
     * @brief Aktualizuje stan kamery silnika
     * 
     * @param dt czas od ostatniej pętli gry w ms
     */
    void update( uint32_t dt ) override;
    /**
     * @brief Obsługuje zdarzenia od biblioteki SDL
     * 
     * @param e zdarzenie
     */
    void handle_event( const SDL_Event& e ) override;

private:
    /**
     * @brief Włącza/wyłącza kontroler
     * 
     * @param b czy aktywować
     */
    void activate( bool b );
};