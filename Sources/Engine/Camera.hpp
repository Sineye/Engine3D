/**
 * @file Camera.hpp
 * @author Przemysław Cedro, Przemysław Ciesek, Kamil Adaś
 * @version 1.0
 * @date 2022-01-28
 */

#pragma once

#include <glm/glm.hpp>

/**
 * @brief Klasa kamery
 * 
 */
class Camera
{
private:
    /**
     * @brief Macierz rzutowania
     */
    glm::mat4 proj_matrix;
    /**
     * @brief Macierz widoku
     */
    glm::mat4 view_matrix;

    /**
     * @brief Pozycja kamery w przestrzeni
     */
    glm::vec3 position;

    /**
     * @brief Kąt obrotu kamery w poziomie
     */
    float yaw;
    /**
     * @brief Kąt obrotu kamery w pionie
     */
    float pitch;

    /**
     * @brief Kierunek kamery
     */
    glm::vec3 heading;
    /**
     * @brief Wektor skierowany w góry względem kamery
     */
    glm::vec3 up;
    /**
     * @brief Wektor skierowany w prawo względem kamery
     */
    glm::vec3 right;
    /**
     * @brief Wektor skierowany wzdłuż osi Y
     */
    const glm::vec3 WORLD_UP { 0.f, 1.f, 0.f };


public:
    /**
     * @brief Konstruktor
     */
    Camera();

    /**
     * @brief Ustawia pozycję kamery w przestrzeni
     * 
     * @param position pozycja
     */
    void set_position( glm::vec3 position );
    /**
     * @brief Zwraca pozycję kamery w przestrzeni
     * 
     * @return pozycja kamery
     */
    glm::vec3 get_position() const;

    /**
     * @brief Ustawia obrót poziomy kamery
     * 
     * @param yaw obrót w stopniach
     */
    void set_yaw( float yaw );
    /**
     * @brief Zwraca obrót kamery w poziomie
     * 
     * @return obrót w poziomie w stopniach
     */
    float get_yaw() const;
    /**
     * @brief Ustawia obrót pionowy kamery
     * 
     * @param yaw obrót w stopniach
     */
    void set_pitch( float pitch );
    /**
     * @brief Zwraca obrót kamery w pionie
     * 
     * @return obrót w pionie w stopniach
     */
    float get_pitch() const;

    /**
     * @brief Zwraca kierunek, w którym skierowana jest kamera
     * 
     * @return wektor kierunkowy
     */
    glm::vec3 get_heading() const;
    /**
     * @brief Zwraca wektor idący w górę względem kamery
     * 
     * @return wektor "do góry" kamery
     */
    glm::vec3 get_up() const;
    /**
     * @brief Zwraca wektor idący w prawo względem kamery
     * 
     * @return wektor "na prawo" kamery
     */
    glm::vec3 get_right() const;

    /**
     * @brief Aktualizuje macierz widoku kamery na podstawie ustawionych wcześniej pozycji i obrotów 
     */
    void update_view_matrix();
    /**
     * @brief Get the view matrix object
     * 
     * @return glm::mat4 
     */
    const glm::mat4& get_view_matrix() const;

    /**
     * @brief Ustawia macierz projekcji kamery
     * 
     * @param mat macierz projekcji
     */
    void set_projection_matrix( const glm::mat4& mat );
    /**
     * @brief Zwraca macierz projekcji kamery
     * 
     * @return macierz projekcji kamery
     */
    const glm::mat4& get_projection_matrix() const;
};