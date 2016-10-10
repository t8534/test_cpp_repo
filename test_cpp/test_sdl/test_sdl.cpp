//============================================================================
// Name        : test_sdl.cpp
//============================================================================

// What about
// http://www.sfml-dev.org/


#include <iostream>
#include <stdio>
#include "SDL2/SDL.h"

using namespace std;

//int main( int argc, char* args[] )
int main() {
	cout << "start" << endl;

	SDL_Window     *window;
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("SDL2 Window", 100, 100, 640, 480, 0);
	if(window==NULL)
	{
		//std::cout << "Could not create window: " << SDL_GetError() << std::endl;
	    printf("Could not create window: %s\n", SDL_GetError());
	    return 1;
	}
	SDL_Delay(3000);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

