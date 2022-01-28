#include "CameraController.hpp"

#include "../Engine/Engine.hpp"

#include <glm/gtx/transform.hpp>

#define ROTATION_SENSITIVITY 10.f

CameraController::CameraController() 
{
    input_move = { 0.f, 0.f };
    input_rotation = { 0.f, 0.f };

    activate(false);
}

void CameraController::update( uint32_t dt ) 
{
    if( is_controller_active )
    {
        Camera& cam = Engine::get_instance()->get_camera();
        float dt_s = (float)dt / 1000.f;

        glm::vec3 forward = cam.get_heading() * input_move.y * dt_s;
        glm::vec3 strafe = cam.get_right() * input_move.x * dt_s;
        cam.set_position( cam.get_position() + forward + strafe );

        cam.set_yaw( cam.get_yaw() + input_rotation.x * ROTATION_SENSITIVITY * dt_s );
        cam.set_pitch( cam.get_pitch() - input_rotation.y * ROTATION_SENSITIVITY * dt_s );
    }

    // we reset these, because they're relative with each frame
    input_rotation = { 0.f, 0.f };
}

void CameraController::handle_event( const SDL_Event& e ) 
{
    if( e.type == SDL_KEYDOWN )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_w:
                input_move.y = 1.f;
                break;
            case SDLK_s:
                input_move.y = -1.f;
                break;
            case SDLK_a:
                input_move.x = -1.f;
                break;
            case SDLK_d:
                input_move.x = 1.f;
                break;
            case SDLK_ESCAPE:
                activate(false);
                break;
        }
    }
    else if( e.type == SDL_KEYUP )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_w:
            case SDLK_s:
                input_move.y = 0.f;
                break;
            case SDLK_a:
            case SDLK_d:
                input_move.x = 0.f;
                break;
        }
    }
    else if( e.type == SDL_MOUSEMOTION )
    {
        input_rotation = { (float)e.motion.xrel, (float)e.motion.yrel };
    }
    else if( e.type == SDL_MOUSEBUTTONDOWN )
    {
        if( e.button.button == SDL_BUTTON_LEFT )
        {
            activate(true);
        }
    }
}

void CameraController::activate( bool b ) 
{
    is_controller_active = b;
    // constrain the mouse inside the window and hide the cursor
    SDL_SetRelativeMouseMode( b ? SDL_TRUE : SDL_FALSE );
}
