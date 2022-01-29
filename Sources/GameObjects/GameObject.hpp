/**
 * @file GameObject.hpp
 * @author Przemysław Cedro, Przemysław Ciesek, Kamil Adaś
 * @version 1.0
 * @date 2022-01-28
 */

#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

/**
 * @brief Podstawowa klasa obiektu gry
 */
class GameObject
{
public:
    /**
     * @brief Flaga wskazujaca, czy obiekt jest wciąż "żywy" i nie powinien być usuwany z silnika
     */
    bool is_alive;

    /**
     * @brief Konstruktor
     */
    GameObject();
    virtual ~GameObject() = default; // interface needs at least virtual destructor
};

#endif // __GAMEOBJECT_H__