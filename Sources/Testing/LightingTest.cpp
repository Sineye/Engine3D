#include "LightingTest.hpp"

#include "../Engine/Engine.hpp"

#include <glm/gtx/transform.hpp>

LightingTest::LightingTest() 
{
    test_angle = 0.f;
    test_input = 0.f;

    lightObj = std::make_shared<LightObject>( GL_LIGHT0 );
    lightObj->translation = { 0.f, 0.f, -4.f };
	lightObj->ambient = { 0.1f, 0.1f, 0.1f, 1.f };
	lightObj->diffuse = { 0.7f, 0.7f, 0.7f, 1.f };
	lightObj->specular = { 1.f, 1.f, 1.f, 1.f };
	lightObj->enable();
	lightObj->update_attributes();

    cubeObj = std::make_shared<CubeObject>( 2.f, glm::vec3( 0.f, 0.f, 1.f ) );
    cubeObj->translation = { 0.f, 0.f, -4.f };

    Engine::get_instance()->add_game_object( lightObj );
    Engine::get_instance()->add_game_object( cubeObj );
}

void LightingTest::update( uint32_t dt ) 
{
    test_angle += test_input * 33.f * (float)dt / 1000.f;
    if( test_angle > 360.f )
    {
        test_angle -= 360.f;
    }
    
    auto m = glm::rotate( glm::radians(test_angle), glm::vec3(1, 0, 0) );
	m = glm::rotate(m, glm::radians(test_angle/2), glm::vec3(0, 1, 0) );
    cubeObj->rotation = m;
}

void LightingTest::handle_event( const SDL_Event& e ) 
{
    if( e.type == SDL_KEYDOWN )
    {
        if( e.key.keysym.sym == SDLK_LEFT )
        {
            test_input = -1.f;
        }
        else if( e.key.keysym.sym == SDLK_RIGHT )
        {
            test_input = 1.f;
        }
    }
    else if( e.type == SDL_KEYUP )
    {
        test_input = 0.f;
    }
}
