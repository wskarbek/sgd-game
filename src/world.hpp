#include <SDL2/SDL.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

#include "spritesheet.hpp"

enum Block {
    AIR = 0,
    WALL = 1,
    DIRT = 2,
    ROCK = 3,
    LAVA = 4,
    START = 5,
    FINISH = 6,
    DIAMOND = 7
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
        std::ifstream inFile;
    public:
        World();
        World(SDL_Renderer * r);
        void render_world();
        void level_load(const char *path);
        void level_unload();
        void load_block_textures();
        void move_camera_to_player();
};