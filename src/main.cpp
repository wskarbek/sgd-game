//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>

#include <game.hpp>

enum GameState {
    MENU, GAME, LEVEL_EDIT
};

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int main( int argc, char* args[] ) {

    bool quit = false;
    int mouseX, mouseY;

    const Uint8 *state = SDL_GetKeyboardState(NULL);

    SDL_Window* gWindow = SDL_CreateWindow( "test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	SDL_Event e;

    SDL_Renderer* renderer = SDL_CreateRenderer(gWindow, -1, 0);

    Game game(renderer);

    SDL_Init( SDL_INIT_VIDEO );

    game.init();

    while(!quit) {
        SDL_RenderClear(renderer);
        //SDL_RenderCopy(renderer, obama, NULL, &obamaRect);
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT ) {
                quit = true;
            }
            if(e.type == SDL_MOUSEMOTION) {
                SDL_GetMouseState(&mouseX, &mouseY);
                //printf("MOUSE X: %i Y: %i \n", mouseX, mouseY);
            }
        }
        game.update();
        game.render();
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(gWindow);

	SDL_Quit();

	return 0;
}