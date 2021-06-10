#include <SDL2/SDL.h>

#include <world.hpp>

struct Player {
    int hp;
    int x, y;
    short moveFreeze = 0;
    Player() {}
};

class Game{
    private:
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        const short MOVE_FREEZE = 10;
        const short PHYSICS_FREEZE = 15;
        short physicsFreeze = 0;
        SDL_Renderer * renderer;
        Player player;
        World world;
    public:
        Game(SDL_Renderer * r);
        ~Game();
        void init();
        void update();
        void render();
};