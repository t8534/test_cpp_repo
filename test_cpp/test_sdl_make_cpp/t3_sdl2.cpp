/*
 * This is working example with drawing line at the window.
 *
 * See:
 * http://wiki.libsdl.org/APIByCategory
 *
 *
 * following on description at:
 * https://www.caveofprogramming.com/c-for-complete-beginners/setting-up-sdl-windows.html
 *
 * The SDL includes and libraries are NOT stored at MinGW, but inside
 * of the project folder.
 *
 *
 */


#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
#endif



#if 0
// Base example. Working.
#include <SDL.h>

int main(int argc, char* argv[]) {
    // Start SDL2
    SDL_Init(SDL_INIT_EVERYTHING);

    // Create a Window in the middle of the screen
    SDL_Window *window = 0;

    window = SDL_CreateWindow("Hello World!",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              640, 480,
                              SDL_WINDOW_SHOWN);

    // Delay so that we can see the window appear
    SDL_Delay(2000);

    // Cleanup and Quit
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
#endif


// Pixel draw example.
#include <SDL.h>

int main(int argc, char* argv[]) {

    // Create a Window in the middle of the screen
    SDL_Window *window = 0;
    SDL_Renderer* renderer;

    SDL_Init(SDL_INIT_EVERYTHING);


    /*
    window = SDL_CreateWindow("Hello World!",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              640, 480,
                              SDL_WINDOW_SHOWN);
    */

    // Create the window where we will draw.
    window = SDL_CreateWindow("SDL_RenderClear",
                            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                            512, 512,
                            0);

    // We must call SDL_CreateRenderer in order for draw calls to affect this window.
    renderer = SDL_CreateRenderer(window, -1, 0);

    // Select the color for drawing. It is set to red here.
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    // Clear the entire screen to our selected color.
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    // Draw here
    SDL_RenderDrawLine(renderer, 10, 10, 200, 200);


    // Up until now everything was drawn behind the scenes.
    // This will show the new, red contents of the window.
    SDL_RenderPresent(renderer);




    // Delay so that we can see the window appear
    SDL_Delay(5000);

    // Cleanup and Quit
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
