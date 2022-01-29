/**
 * @file SimpleEventListeningObject.hpp
 * @author Przemysław Cedro, Przemysław Ciesek, Kamil Adaś
 * @version 1.0
 * @date 2022-01-28
 */

#ifndef __SIMPLEEVENTLISTENINGOBJECT_H__
#define __SIMPLEEVENTLISTENINGOBJECT_H__

#include "EventListeningObject.hpp"

#include <functional>

/**
 * @brief Obiekt mający wywoływać prostą procedurę obsługi zdarzenia
 */
class SimpleEventListeningObject : virtual public EventListeningObject
{
protected:
    /**
     * @brief Funkcja wywoływana przez klasę
     * 
     */
    std::function< void( const SDL_Event& ) > lambda_handler;

public:
    /**
     * @brief Konstruktor
     * 
     * @param lambda funkcja lambda wykonująca prostą operację obsługi zdarzenia
     */
    SimpleEventListeningObject( std::function< void( const SDL_Event& ) > lambda );

    /**
     * @brief Metoda, do której podawane jest zdarzenie, gdy to następuje
     * 
     * @param e zdarzenie
     */
    void handle_event( const SDL_Event& e ) override;
};

#endif // __SIMPLEEVENTLISTENINGOBJECT_H__