#pragma once

#include "../GameObjects/DrawableObject.hpp"
#include "../GameObjects/EventListeningObject.hpp"
#include "../GameObjects/UpdatableObject.hpp"

class FirstCubeTestObject : virtual public DrawableObject, virtual public EventListeningObject, virtual public UpdatableObject
{
public:
    void update( uint32_t dt ) override;
    void handle_event( const SDL_Event& e ) override;
    void draw() override;
};