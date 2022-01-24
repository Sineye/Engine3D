#pragma once

#include "../GameObjects/UpdatableObject.hpp"
#include "../GameObjects/EventListeningObject.hpp"
#include "../GameObjects/LightObject.hpp"
#include "../GameObjects/TexturedCubeObject.hpp"

#include <memory>

class LightingTest : virtual public UpdatableObject, virtual public EventListeningObject
{
private:
    float cube_angle;
    float cube_input;
    float camera_angle;
    float camera_input;

    std::shared_ptr<LightObject> lightObj;
    std::shared_ptr<TexturedCubeObject> cubeObj;

public:
    LightingTest();

    void update( uint32_t dt ) override;
    void handle_event( const SDL_Event& e ) override;
};