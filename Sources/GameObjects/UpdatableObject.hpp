/**
 * @file UpdatableObject.hpp
 * @author Przemysław Cedro, Przemysław Ciesek, Kamil Adaś
 * @version 1.0
 * @date 2022-01-28
 */

#ifndef __UPDATABLEOBJECT_H__
#define __UPDATABLEOBJECT_H__

#include "GameObject.hpp"

#include <cstdint>

/**
 * @brief Interfejs klas, których stan należy aktualizować z każdą iteracją pętli głównej gry
 */
class UpdatableObject : virtual public GameObject
{
public:
    /**
     * @brief Metoda wywoływana przy każdej iteracji pętli gry
     * 
     * @param dt czas od ostatniej iteracji w ms
     */
    virtual void update( uint32_t dt ) = 0;

    virtual ~UpdatableObject() = default;
};

#endif // __UPDATABLEOBJECT_H__