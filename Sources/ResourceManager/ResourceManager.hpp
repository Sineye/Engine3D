/**
 * @file ResourceManager.hpp
 * @author Przemysław Cedro, Przemysław Ciesek, Kamil Adaś
 * @version 1.0
 * @date 2022-01-28
 */

#ifndef __RESOURCEMANAGER_H__
#define __RESOURCEMANAGER_H__

#include "../Texture/Texture.hpp"

#include <string>
#include <unordered_map>

/**
 * @brief Klasa zajmująca się ładowaniem i przetrzymywaniem zasobów
 */
class ResourceManager
{
private:
    /**
     * @brief Mapa ścieżki do tekstury do wskaźnika na tę teksturę
     */
    static std::unordered_map< std::string, Texture* > map_path_to_texture;

public:
    /**
     * @brief Destruktor, zwalnia wszystkie załadowane zasoby
     */
    ~ResourceManager();

    /**
     * @brief Metoda ładująca i zwracająca teksturę
     * 
     * @param path ścieżka do pliku tekstury
     * @return wskaźnik na załadowaną teksturę lub nullptr jeśli nie udało się jej załadować
     */
    static Texture *load_texture( const char* path );
    /**
     * @brief Zwalnia pamięć z tekstury, którą rozpoznaje po ścieżce do jej pliku
     * 
     * @param path ścieżka do pliku tekstury
     */
    static void unload_texture( const char *path );
};

#endif // __RESOURCEMANAGER_H__