#include <SDL2/SDL.h>
#include <stdio.h>
#include <vector>

#include <world.hpp>

const int BLOCKSIZE = 48;

World::World() {
    
}

World::World(SDL_Renderer * r, int x, int y) {
    renderer = r;
    sizeX = x;
    sizeY = y;
    renderX = 0;
    renderY = 0;
}

void World::render_world() {
    for(int mapY = 0; mapY < sizeY; mapY++) {
        for(int mapX = 0; mapX < sizeX; mapX++) {
            SDL_Rect blockRect = {mapX * BLOCKSIZE + renderX, mapY * BLOCKSIZE + renderY, BLOCKSIZE, BLOCKSIZE };
            //16x16 block 10x8
            Block blockId = map.at(mapY).at(mapX);
            switch(blockId) {
                case STONE:
                    spritesheet.select_sprite(0, 3);
                    spritesheet.draw_selected_sprite(&blockRect);
                    break;
                case DIRT:
                    spritesheet.select_sprite(4, 3);
                    spritesheet.draw_selected_sprite(&blockRect);
                    break;
                case ROCK:
                    spritesheet.select_sprite(5, 3);
                    spritesheet.draw_selected_sprite(&blockRect);
                    break;
                case LAVA:
                    spritesheet.select_sprite(3, 4);
                    spritesheet.draw_selected_sprite(&blockRect);
                    break;
                case FINISH:
                    spritesheet.select_sprite(1, 3);
                    spritesheet.draw_selected_sprite(&blockRect);
                    break;
                case DIAMOND:
                    spritesheet.select_sprite(0, 4);
                    spritesheet.draw_selected_sprite(&blockRect);
                    break;
            }
        }
    }
}

void World::load_block_textures() {
    spritesheet = Spritesheet(renderer, "sprites.png", 8, 10);
    //blockSurfaceStone = SDL_LoadBMP( "obama.bmp" );
    //blockTextureStone = SDL_CreateTextureFromSurface(renderer, blockSurfaceStone);
    //SDL_FreeSurface(blockSurfaceStone);
}

void World::move_camera_to_player() {

}

void World::test_generate() {
    for(int mapY = 0; mapY < sizeY; mapY++) {
        std::vector<Block> tmp;
        for(int mapX = 0; mapX < sizeX; mapX++) {
            tmp.push_back(ROCK);
        }
        map.push_back(tmp);
    }
}