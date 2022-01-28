#pragma once

#include "EventListeningObject.hpp"
#include "UpdatableObject.hpp"

#include <glm/glm.hpp>

class CameraController : virtual public EventListeningObject,
                         virtual public UpdatableObject
{
private:
    bool is_controller_active;

    glm::vec2 input_move; // x for strafing, y for forward/backwards
    glm::vec2 input_rotation; // x for yaw, y for pitch


public:
    CameraController();

    void update( uint32_t dt ) override;
    void handle_event( const SDL_Event& e ) override;

private:
    void activate( bool b );
};