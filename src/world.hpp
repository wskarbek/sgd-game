#include <SDL2/SDL.h>
#include <vector>

#include "spritesheet.hpp"

enum Block {
    STONE, DIRT, ROCK, LAVA, START, FINISH, DIAMOND
};

class World {
    private:
        int sizeX, sizeY; // Size of world
        int renderX, renderY; // World render offset
        SDL_Renderer * renderer;
        SDL_Surface * blockSurfaceStone;
        SDL_Texture * blockTextureStone;
        Spritesheet spritesheet;
        std::vector<std::vector<Block>> map;
    public:
        World();
        World(SDL_Renderer * renderer, int x, int y);
        void load_block_textures();
        void render_world();
        void move_camera_to_player();
        void test_generate();
};