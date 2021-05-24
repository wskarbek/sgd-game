#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>

#include <game.hpp>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] ) {

    bool quit = false;
    int mouseX, mouseY;

    SDL_Window* gWindow = SDL_CreateWindow( "Yet Another Boulder Dash Clone", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	SDL_Event e;

    SDL_Renderer* renderer = SDL_CreateRenderer(gWindow, -1, 0);

    SDL_Init( SDL_INIT_VIDEO );

    Game game(renderer);

    game.init();

    while(!quit) {
        SDL_RenderClear(renderer);
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT ) {
                quit = true;
            }
            if(e.type == SDL_MOUSEMOTION) {
                SDL_GetMouseState(&mouseX, &mouseY);
            }
        }
        game.update();
        game.render();
        printf("%s", SDL_GetError());
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(gWindow);

	SDL_Quit();

	return 0;
}