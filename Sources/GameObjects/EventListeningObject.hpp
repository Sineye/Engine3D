/**
 * @file EventListeningObject.hpp
 * @author Przemysław Cedro, Przemysław Ciesek, Kamil Adaś
 * @version 1.0
 * @date 2022-01-28
 */

#ifndef __EVENTLISTENINGOBJECT_H__
#define __EVENTLISTENINGOBJECT_H__

#include "GameObject.hpp"

#include <SDL_events.h>

/**
 * @brief Interfejs dla klas, które chcą obsługiwać zdarzenia z SDL2
 */
class EventListeningObject : virtual public GameObject
{
public:
    /**
     * @brief Metoda, która jest wywoływana przy wytąpieniu zdarzenia
     * 
     * @param e zdarzenie
     */
    virtual void handle_event( const SDL_Event& e ) = 0;
    
    virtual ~EventListeningObject() = default;
};

#endif // __EVENTLISTENINGOBJECT_H__