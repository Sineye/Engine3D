#define ENABLE_TESTING

#include <stdlib.h>

#include "Engine/Engine.hpp"
#include "Testing/LightingTest.hpp"

#ifdef _WIN32
#undef main
#endif

int main()
{
    Engine * engine = Engine::get_instance("Engine3D", 64, 64, 512, 512, WINDOWED_MODE, 60);

#ifdef ENABLE_TESTING
	engine->add_game_object( new LightingTest() );
#endif

    while (engine->is_running)
	{
		engine->process_events();
		engine->schedule();
		engine->draw();
	}

	delete engine;

    return EXIT_SUCCESS;
}