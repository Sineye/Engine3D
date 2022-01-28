#include "LightingTest.hpp"

#include "../Engine/Engine.hpp"
#include "../PrimitiveRendering/TexturedCube.hpp"
#include "../PrimitiveRendering/ColoredCube.hpp"
#include "../PrimitiveRendering/PrimitiveRenderer.hpp"
#include "../GameObjects/SimpleDrawableObject.hpp"
#include "../PrimitiveRendering/Sphere.hpp"

#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

LightingTest::LightingTest() 
{
    cube_angle = cube_input = 0.f;

    lightObj = std::make_shared<LightObject>( GL_LIGHT0 );
    lightObj->translation = { 4.f, 5.f, -5.f };
	lightObj->ambient = { 0.1f, 0.1f, 0.1f, 1.f };
	lightObj->diffuse = { 1.f, 1.f, 1.f, 1.f };
	lightObj->specular = { 1.f, 1.f, 1.f, 1.f };
	lightObj->enable();
	lightObj->update_attributes();

    cubeObj = std::make_shared<MeshObject>( new TexturedCube( 1.f, "../tyler.jpg" ) );
    cubeObj->translation = { 0.f, 0.f, -4.f };

    Engine::get_instance()->add_game_object( lightObj );
    Engine::get_instance()->add_game_object( cubeObj );
    Engine::get_instance()->add_game_object( new SimpleDrawableObject(
        [] {
            glMatrixMode( GL_MODELVIEW );
            glLoadMatrixf( glm::value_ptr( Engine::get_instance()->get_camera().get_view_matrix() ) );

            PrimitiveRenderer::draw_quad(
                {-25.f, -1.f, -25.f },
                { 25.f, -1.f, -25.f },
                { 25.f, -1.f,  25.f },
                {-25.f, -1.f,  25.f },
                {0.f, 0.5f, 1.f}
            );
        }
    ));


    sphereObj = std::make_shared<MeshObject>( new Sphere( 0.25f, 36, 18, glm::vec3( 1.f, 0.8f, 0.f ) ) );
    sphereObj->translation = { -2.f, 0.f, -4.f };
    Engine::get_instance()->add_game_object( sphereObj );

    sphereLight = std::make_shared<LightObject>( GL_LIGHT1 );
    sphereLight->translation = { -1.5f, 0.f, -4.f };
	sphereLight->ambient = { 0.1f, 0.1f, 0.1f, 1.f };
	sphereLight->diffuse = { 1.f, 1.f, 0.f, 1.f };
	sphereLight->specular = { 1.f, 1.f, 0.f, 1.f };
	sphereLight->enable();
	sphereLight->update_attributes();
    Engine::get_instance()->add_game_object( sphereLight );

    sphere_angle = 0.f;


    Engine::get_instance()->get_camera().set_yaw( -90.f );
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


    sphere_angle += 33.f * (float)dt / 1000.f;
    if( sphere_angle > 360.f )
    {
        sphere_angle -= 360.f;
    }

    glm::vec3 sphere_offset;
    sphere_offset.x = glm::cos( glm::radians( sphere_angle ) );
    sphere_offset.y = 0.f;
    sphere_offset.z = glm::sin( glm::radians( sphere_angle ) );
    sphere_offset = glm::normalize( sphere_offset );

    sphereObj->translation = cubeObj->translation + sphere_offset * 2.f;
    sphereLight->translation = cubeObj->translation + sphere_offset * 1.75f;
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
        }
    }
}
