#include <SDL2/SDL.h>

#include <world.hpp>

class Game{
    private:
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        SDL_Renderer * renderer;
        World world;
    public:
        Game(SDL_Renderer * r);
        ~Game();
        void init();
        void update();
        void render();
};