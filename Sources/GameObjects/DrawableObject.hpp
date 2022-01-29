/**
 * @file DrawableObject.hpp
 * @author Przemysław Cedro, Przemysław Ciesek, Kamil Adaś
 * @version 1.0
 * @date 2022-01-28
 */

#ifndef __DRAWABLEOBJECT_H__
#define __DRAWABLEOBJECT_H__

#include "GameObject.hpp"

/**
 * @brief Interfejs dla klas, które chcą coś renderować
 */
class DrawableObject : virtual public GameObject
{
public:
    /**
     * @brief Metoda wywoływana przez silnik w kroku renderowania
     */
    virtual void draw() = 0;
    
    virtual ~DrawableObject() = default;
};

#endif // __DRAWABLEOBJECT_H__