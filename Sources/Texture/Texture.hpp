/**
 * @file Texture.hpp
 * @author Przemysław Cedro, Przemysław Ciesek, Kamil Adaś
 * @version 1.0
 * @date 2022-01-28
 */

#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

/**
 * @brief Klasa reprezentująca teksturę
 */
class Texture
{
private:
    /**
     * @brief Identyfikator tekstury
     */
    GLuint id;
    /**
     * @brief Wielkość tekstury
     */
    glm::ivec2 size;
    /**
     * @brief Format tekstury
     */
    GLenum format;

public:
    /**
     * @brief Konstruktor
     */
    Texture();
    /**
     * @brief Destruktor
     */
    ~Texture();

    /**
     * @brief Ładuje teksturę z pliku
     * 
     * @param path ścieżka do pliku
     * @return czy ładowanie przebiegło pomyślnie
     */
    bool load( const char *path );

    /**
     * @brief Zwraca identyfikator OpenGL tekstury
     * 
     * @return ID tekstury
     */
    GLuint get_id() const;
    /**
     * @brief Zwraca wielkość tekstury
     * 
     * @return wielkość tekstury
     */
    glm::ivec2 get_size() const;
    /**
     * @brief Zwraca format w jakim została załadowana tekstura (RGB, RGBA itd.) 
     * 
     * @return format tekstury
     */
    GLenum get_format() const;
};