#include "Engine.hpp"
#include "GameObjects/EventListeningObject.hpp"
#include "GameObjects/UpdatableObject.hpp"
#include "GameObjects/DrawableObject.hpp"

#include <glm/ext.hpp>

Engine * Engine::engine = nullptr;

Engine::Engine(const char * title, int x, int y, int w, int h, WindowMode window_mode, unsigned frame_rate)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	// after SDL init and before creating a window we need to tell SDL what version of OpenGL we want to use
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 1 );
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );

	sdl_window = SDL_CreateWindow(title, x, y, w, h, window_mode | SDL_WINDOW_OPENGL );
	if (!sdl_window)
	{
		LOG("Unable to create window.");
		LOG(SDL_GetError());
		exit(EXIT_FAILURE);
	}

	// we also need to explicitly create a context for OpenGL operations (and make it current)
	sdl_gl_context = SDL_GL_CreateContext( sdl_window );
	if( !sdl_gl_context )
	{
		LOG("Unable to create GL context.");
		LOG(SDL_GetError());
		exit(EXIT_FAILURE);
	}

	// set basic GL properties
	glViewport( 0, 0, w, h );
	glClearColor( 0.f, 0.f, 0.f, 1.f );

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	glEnable( GL_DEPTH_TEST );

	glEnable( GL_LIGHTING );
	GLfloat lightAmb[] = {0.2f, 0.2f, 0.2f, 1.0f}; 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lightAmb); // ambient lighting

	GLfloat lightSpc[] = {1.f, 1.f, 1.f, 1.f};
	glMaterialfv(GL_FRONT, GL_SPECULAR, lightSpc); // common specular material attribute
	glMateriali(GL_FRONT, GL_SHININESS, 64); // common shininess material attribute

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glEnable( GL_TEXTURE_2D );

	camera.view_matrix = glm::mat4(1.f);
	set_projection_mode( PROJECTION_PERSPECTIVE );

	previous_time = 0;
	target_time = 1000 / frame_rate;

	is_running = true;

	GLenum err =  glGetError();
	if( err != GL_NO_ERROR )
	{
		LOG( gluErrorString(err) );
	}
}

Engine::~Engine()
{
	vec_game_objects.clear();

	SDL_GL_DeleteContext( sdl_gl_context );
	SDL_DestroyWindow(sdl_window);

	SDL_Quit();
}

Engine * Engine::get_instance() 
{
	if(!engine)
	{
		engine = new Engine("", 0, 0, 800, 600, WindowMode::WINDOWED_MODE, 60);
	}

	return engine;
}

Engine * Engine::get_instance(const char * title, int x, int y, int w, int h, WindowMode window_mode, unsigned frame_rate)
{
	if (!engine)
	{
		engine = new Engine(title, x, y, w, h, window_mode, 60);
	}

	return engine;
}

void Engine::schedule()
{
	uint32_t current_time = SDL_GetTicks();
	uint32_t elapsed_time = current_time - previous_time;
	uint32_t updates_to_make = elapsed_time / target_time + 1;

	bool should_sleep = (updates_to_make == 1);

	while( updates_to_make > 0 )
	{
		remove_dead_game_objects();
		update();
		updates_to_make--;
	}

	if( should_sleep )
	{
		SDL_Delay( target_time - elapsed_time );
	}

	previous_time = current_time;
}

void Engine::process_events()
{
	SDL_Event event;
	EventListeningObject *elo;

	while (SDL_PollEvent(&event))
	{
		for( int i = 0; i < vec_game_objects.size(); i++ )
		{
			GameObject *go = vec_game_objects[i].get();
			elo = dynamic_cast<EventListeningObject *>(go);
			if( go->is_alive && elo )
			{
				elo->handle_event(event);
			}
		}

		if( event.type == SDL_QUIT )
		{
			is_running = false;
		}
	}
}

void Engine::update()
{
	UpdatableObject *updatable;

	for( int i = 0; i < vec_game_objects.size(); i++ )
	{
		GameObject *go = vec_game_objects[i].get();
		updatable = dynamic_cast<UpdatableObject *>(go);
		if( go->is_alive && updatable )
		{
			updatable->update( target_time );
		}
	}
}

void Engine::draw()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	
	DrawableObject *dob;

	for( int i = 0; i < vec_game_objects.size(); i++ )
	{
		GameObject *go = vec_game_objects[i].get();
		dob = dynamic_cast<DrawableObject *>(go);
		if( go->is_alive && dob )
		{
			dob->draw();
		}
	}

	SDL_GL_SwapWindow( sdl_window );
}

void Engine::add_game_object( std::shared_ptr<GameObject> go ) 
{
	if( go )
	{
		vec_game_objects.push_back( go );
	}
	
}

void Engine::add_game_object( GameObject *go, bool renounce_ownership ) 
{
	if( go )
	{
		if( renounce_ownership )
		{
			vec_game_objects.push_back( std::shared_ptr<GameObject>( go ) );
		}
		else
		{
			// add a shared_ptr with an empty deletor so the object won't actually get deleted when it'll get removed
			vec_game_objects.push_back( std::shared_ptr<GameObject>( go, []( GameObject *go ){} ) );
		}
	}
}

void Engine::remove_dead_game_objects() 
{
	auto it = vec_game_objects.begin();
	while( it != vec_game_objects.end() )
	{
		if( !(*it)->is_alive )
		{
			// erase moves all subsequent elements towards the beginning of the vector 
			// and returns an iterator to the element after the erased one
			// by assigning that returned interator to `it` we iterate onto the next element
			it = vec_game_objects.erase(it);
		}
		else
		{
			// if we don't erase we simply increment the iterator
			++it;
		}
	}
}

void Engine::set_projection_mode( ProjectionMode mode ) 
{
	int w, h;
	SDL_GetWindowSize( sdl_window, &w, &h );

	if( mode == PROJECTION_ORTHOGRAPHIC )
	{
		camera.proj_matrix = glm::ortho( 0.f, (float)w, 0.f, (float)h );
	}
	else
	{
		camera.proj_matrix = glm::perspective( glm::radians( 50.f ), (float)w / (float)h, 1.f, 100.f );
	}

	glMatrixMode( GL_PROJECTION );
	glLoadMatrixf( glm::value_ptr( camera.proj_matrix ) );
}

Camera& Engine::get_camera() 
{
	return this->camera;
}
