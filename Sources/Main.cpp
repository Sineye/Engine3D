#include <stdlib.h>

#include "Engine/Engine.hpp"

#ifdef _WIN32
#undef main
#endif

int main()
{
    Engine * engine = Engine::get_instance("Tech Demo", 64, 64, 512, 512, WINDOWED_MODE, 60);

    while (engine->is_running)
	{
		engine->process_events();
		engine->schedule();
		engine->draw();
	}

	delete engine;

    return EXIT_SUCCESS;
}