//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>

#include <world.h>

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int main( int argc, char* args[] ) {

    bool quit = false;
    int mouseX, mouseY;

    const Uint8 *state = SDL_GetKeyboardState(NULL);

    SDL_Window* gWindow = SDL_CreateWindow( "test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	SDL_Event e;

    SDL_Surface* gScreenSurface = SDL_GetWindowSurface( gWindow );

    SDL_Renderer* renderer = SDL_CreateRenderer(gWindow, -1, 0);

    SDL_Surface* gHelloWorld = SDL_LoadBMP( "obama.bmp" );
    SDL_Rect obamaRect = {5, 5, 100, 100 };
    SDL_Texture* obama = SDL_CreateTextureFromSurface(renderer, gHelloWorld);

    SDL_Init( SDL_INIT_VIDEO );

    World world(renderer, 10, 10);
    world.load_block_textures();
    world.test_generate();
    while(!quit) {
        //SDL_RenderClear(renderer);
        //SDL_RenderCopy(renderer, obama, NULL, &obamaRect);
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT ) {
                quit = true;
            }
            if(e.type == SDL_MOUSEMOTION) {
                SDL_GetMouseState(&mouseX, &mouseY);
                //printf("MOUSE X: %i Y: %i \n", mouseX, mouseY);
                obamaRect.x = mouseX;
                obamaRect.y = mouseY;
            }
        }
        if (state[SDL_SCANCODE_RIGHT]) {
            printf("RIGHT");
            obamaRect.x++;
        }
        if (state[SDL_SCANCODE_LEFT]) {
            printf("LEFT");
            obamaRect.x--;
        }
        if (state[SDL_SCANCODE_UP]) {
            printf("UP");
            obamaRect.y--;
        }
        if (state[SDL_SCANCODE_DOWN]) {
            printf("DOWN");
            obamaRect.y++;
        }
        world.render_world();
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(obama);
    SDL_FreeSurface(gHelloWorld);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(gWindow);

	SDL_Quit();

	return 0;
}