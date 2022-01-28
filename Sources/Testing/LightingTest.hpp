#pragma once

#include "../GameObjects/UpdatableObject.hpp"
#include "../GameObjects/EventListeningObject.hpp"
#include "../GameObjects/LightObject.hpp"
#include "../GameObjects/MeshObject.hpp"

#include <memory>

class LightingTest : virtual public UpdatableObject, virtual public EventListeningObject
{
private:
    float cube_angle;
    glm::vec2 cube_input; // x for rotation, y for scale

    std::shared_ptr<LightObject> lightObj;
    std::shared_ptr<MeshObject> cubeObj;

    std::shared_ptr<MeshObject> sphereObj;
    std::shared_ptr<LightObject> sphereLight;
    float sphere_angle;

public:
    LightingTest();

    void update( uint32_t dt ) override;
    void handle_event( const SDL_Event& e ) override;
};