#include "LightingTest.hpp"

#include "../Engine/Engine.hpp"

#include <glm/gtx/transform.hpp>

LightingTest::LightingTest() 
{
    cube_angle = cube_input = camera_angle = camera_input = 0.f;

    lightObj = std::make_shared<LightObject>( GL_LIGHT0 );
    lightObj->translation = { 2.f, 2.f, 0.f };
	lightObj->ambient = { 0.1f, 0.1f, 0.1f, 1.f };
	lightObj->diffuse = { 0.7f, 0.7f, 0.7f, 1.f };
	lightObj->specular = { 1.f, 1.f, 1.f, 1.f };
	lightObj->enable();
	lightObj->update_attributes();

    cubeObj = std::make_shared<TexturedCubeObject>( 1.f, "../tex0.tga" );
    cubeObj->translation = { 0.f, 0.f, -4.f };

    Engine::get_instance()->add_game_object( lightObj );
    Engine::get_instance()->add_game_object( cubeObj );
}

void LightingTest::update( uint32_t dt ) 
{
    cube_angle += cube_input * 33.f * (float)dt / 1000.f;
    if( cube_angle > 360.f )
    {
        cube_angle -= 360.f;
    }
    
    auto m = glm::rotate( glm::radians(cube_angle), glm::vec3(0, 1, 0) );
    cubeObj->rotation = m;


    camera_angle += camera_input * 33.f * (float)dt / 1000.f;
    if( camera_angle > 360.f )
    {
        camera_angle -= 360.f;
    }

    m = glm::translate( cubeObj->translation );
    m = glm::rotate( m, glm::radians(camera_angle), glm::vec3(0, 1, 0) );
    m = glm::translate( m, glm::vec3(0, 0, 5) );
    Engine::get_instance()->get_camera().view_matrix = m;
}

void LightingTest::handle_event( const SDL_Event& e ) 
{
    if( e.type == SDL_KEYDOWN )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_LEFT:
                cube_input = -1.f;
                break;
            case SDLK_RIGHT:
                cube_input = 1.f;
                break;
            case SDLK_a:
                camera_input = -1.f;
                break;
            case SDLK_d:
                camera_input = 1.f;
                break;
            case SDLK_z:
                Engine::get_instance()->set_projection_mode( PROJECTION_ORTHOGRAPHIC );
                break;
            case SDLK_x:
                Engine::get_instance()->set_projection_mode( PROJECTION_PERSPECTIVE );
                break;
        }       
    }
    else if( e.type == SDL_KEYUP )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_LEFT:
            case SDLK_RIGHT:
                cube_input = 0.f;
                break;
            case SDLK_a:
            case SDLK_d:
                camera_input = 0.f;
                break;
        }
    }
}
