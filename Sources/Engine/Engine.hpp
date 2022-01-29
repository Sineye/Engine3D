/**
 * @file Engine.hpp
 * @author Przemysław Cedro, Przemysław Ciesek, Kamil Adaś
 * @version 1.0
 * @date 2022-01-28
 */

#pragma once

// these SDL and GL includes have to be in this very specific order, DON'T CHANGE IT!
#include <SDL.h>
#include <GL/glew.h>
#include <SDL_opengl.h>

#include "Utility/Log.hpp"
#include "GameObjects/GameObject.hpp"
#include "Camera.hpp"

#include <memory>
#include <vector>

/**
 * @brief Enum trybu okna aplikacji
 */
enum WindowMode
{
	/**
	 * @brief Wyświetlanie w oknie
	 */
    WINDOWED_MODE,
	/**
	 * @brief Wyświetlanie w oknie bez ramki
	 */
    BORDERLESS_MODE = SDL_WINDOW_FULLSCREEN_DESKTOP,
	/**
	 * @brief Wyświetlanie pełnoekranowe
	 */
    FULLSCREEN_MODE = SDL_WINDOW_FULLSCREEN
};

/**
 * @brief Enum trybu rzutowania kamery
 * 
 */
enum ProjectionMode
{
	/**
	 * @brief Rzutowanie równoległe
	 */
	PROJECTION_ORTHOGRAPHIC,
	/**
	 * @brief Rzutowanie perspektywiczne
	 */
	PROJECTION_PERSPECTIVE
};

/**
 * @brief Enum trybu cieniowania
 */
enum ShadingMode
{
	/**
	 * @brief Cieniowanie płaskie
	 */
	SHADING_MODE_FLAT	= GL_FLAT,
	/**
	 * @brief Cieniowanie gładkie
	 */
	SHADING_MODE_SMOOTH = GL_SMOOTH
};

/**
 * @brief Klasa singletona silnika 3D
 */
class Engine
{
public:
	/**
	 * @brief Zwraca nową domyślną lub już istniejącą instancję klasy
	 * 
	 * @return wskaźnik na silnik
	 */
	static Engine * get_instance();
	/**
	 * @brief Zwraca nową lub już istniejącą instancję klasy
	 * 
	 * @param title tytuł okna
	 * @param x pozycja X okna
	 * @param y pozycja Y okna
	 * @param w szerokość okna
	 * @param h wysokość okna
	 * @param window_mode tryb okna
	 * @param frame_rate częstotliwość wyświetlania okna
	 * @return wskaźnik na silnik
	 */
	static Engine * get_instance(const char * title, int x, int y, int w, int h, WindowMode window_mode, unsigned frame_rate);
	/**
	 * @brief Destruktor, zwalnia wszelkie wcześniej zajęte zasoby
	 */
	~Engine();

	/**
	 * @brief Flaga wskazująca, czy silnik wciąż pracuje
	 * 
	 */
	bool is_running;
	/**
	 * @brief Funkcja gospodarująca wydarzeniami związanymi z czasem w silniku.
	 */
	void schedule();
	/**
	 * @brief Metoda obsługująca i wysyłająca zdarzenia SDL do obiektów EventListening
	 */
	void process_events();
	/**
	 * @brief Metoda aktualizująca stan podsystemów silnika i obiektów Updatable
	 */
	void update();
	/**
	 * @brief Metoda czyszcząca ekran i renderująca obiekty Drawable
	 */
	void draw();

	/** 
	 * @brief Funkcja dodająca obiekt związany z grą do puli obiektów. Aby go usunąc należy ustawić jego flagę is_alive na false
	 * @param go Dodawany obiekt.
	 */
	void add_game_object( std::shared_ptr<GameObject> go );
	// Adds object to engine's game object pool
	// If you want the engine to let go of ther pointer, set is_alive to false in the object
	// Depending on renounce_ownership value, takes the ownership or only weakly references the pointer

	/**
	 * @brief Funkcja dodająca obiekt związany z grą do puli obiektów. Aby go usunąc należy ustawić jego flagę is_alive na false
	 * 
	 * @param go dodawany obiekt
	 * @param renounce_ownership jeśli ta flaga jest ustawiona na true, silnik staje sie właścicielem wskaźnika i może wykonać na nim delete.
	 */
	void add_game_object( GameObject *go, bool renounce_ownership = true );

	/**
	 * @brief Ustawia tryb rzutowania 
	 * 
	 * @param mode tryb rzutowania
	 */
	void set_projection_mode( ProjectionMode mode );

	/**
	 * @brief Zwraca obiekt kamery silnika
	 * 
	 * @return kamera
	 */
	Camera& get_camera();

	/**
	 * @brief Ustawia tryb cieniowania
	 * 
	 * @param mode tryb cieniowania
	 */
	void set_shading_mode( ShadingMode mode );
	
	
public:
	/**
	 * @brief Wskaźnik na okno SDL
	 */
	SDL_Window * sdl_window;
	/**
	 * @brief Wskaźnik na kontekst OpenGL
	 */
	SDL_GLContext sdl_gl_context;


private:
	/**
	 * @brief Prywatny konstruktor singletona
	 * 
	 * @param title tytuł okna
	 * @param x pozycja X okna
	 * @param y pozycja Y okna
	 * @param w szerokość okna
	 * @param h wysokość okna
	 * @param window_mode tryb okna
	 * @param frame_rate częstotliwość wyświetlania okna
	 */
	Engine(const char * title, int x, int y, int w, int h, WindowMode window_mode, unsigned frame_rate);
	/**
	 * @brief Statyczna instancja silnika
	 */
	static Engine * engine;

	/**
	 * @brief Czas silnika przy poprzedniej klatce
	 */
	uint32_t previous_time;
	/**
	 * @brief Czas silnika przy następnej klatce
	 */
	uint32_t target_time;
	
	/**
	 * @brief Wektor obiektów gry
	 */
	std::vector< std::shared_ptr<GameObject> > vec_game_objects;
	/**
	 * @brief Usuwa "martwe" obiekty gry
	 */
	void remove_dead_game_objects();

	/**
	 * @brief Obiekt kamery
	 */
	Camera camera;
};