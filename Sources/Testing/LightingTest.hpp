#pragma once

#include "../GameObjects/UpdatableObject.hpp"
#include "../GameObjects/EventListeningObject.hpp"
#include "../GameObjects/LightObject.hpp"
#include "../GameObjects/CubeObject.hpp"

#include <memory>

class LightingTest : virtual public UpdatableObject, virtual public EventListeningObject
{
private:
    float test_angle;
    float test_input;

    std::shared_ptr<LightObject> lightObj;
    std::shared_ptr<CubeObject> cubeObj;

public:
    LightingTest();

    void update( uint32_t dt ) override;
    void handle_event( const SDL_Event& e ) override;
};