#include <SDL2/SDL.h>
#include "world.cpp"

class Game{
    private:
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        SDL_Renderer * renderer;
        World world;
    public:
        Game(SDL_Renderer * r) {
            renderer = r;
        }

        ~Game() {}

        void init() {
            world = World(renderer);
            world.load_block_textures();
            world.level_load("../resources/levels/1.lvl");
        }

        void update() {
                if (state[SDL_SCANCODE_RIGHT]) {
                
                }
                if (state[SDL_SCANCODE_LEFT]) {

                }
                if (state[SDL_SCANCODE_UP]) {
                
                }
                if (state[SDL_SCANCODE_DOWN]) {

                }
        }

        void render() {
            world.render_world();
        }
};