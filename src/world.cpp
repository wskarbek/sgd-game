#include <world.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <vector>

World::World(SDL_Renderer * renderer, int x, int y) {
    sizeX = x;
    sizeY = y;
    renderX = 0;
    renderY = 0;
}

void World::render_world() {
    for(int mapY = 0; mapY < sizeY; mapY++) {
        for(int mapX = 0; mapX < sizeX; mapX++) {
            SDL_Rect blockRect = {mapX + renderY, mapY + renderY, 64, 64 };
            SDL_Texture* blockTexture;
            Block blockId = map.at(mapY).at(mapX);
            switch(blockId) {
                case STONE:
                    blockTexture = SDL_CreateTextureFromSurface(renderer, blockTextureStone);
                    SDL_RenderCopy(renderer, blockTexture, NULL, &blockRect);
                    break;
                case DIRT:
                    break;
                case ROCK:
                    break;
                case LAVA:
                    break;
                case FINISH:
                    break;
                case DIAMOND:
                    break;
            }
        }
    }
}

void World::load_block_textures() {
    blockTextureStone = SDL_LoadBMP( "obama.bmp" );
}

void World::move_camera_to_player() {

}

void World::test_generate() {
    for(int mapY = 0; mapY < sizeY; mapY++) {
        std::vector<Block> tmp;
        for(int mapX = 0; mapX < sizeX; mapX++) {
            tmp.push_back(STONE);
        }
        map.push_back(tmp);
    }
}