#include <SDL2/SDL.h>

#include <world.hpp>

const int BLOCKSIZE = 48;

World::World() {
    
}

World::World(SDL_Renderer * renderer) {
    this->renderer = renderer;
    this->renderX = 0;
    this->renderY = 0;
}

void World::render_world() {
    int sizeY = map.size();
    int sizeX = map.at(0).size();
    for(int mapY = 0; mapY < sizeY; mapY++) {
        for(int mapX = 0; mapX < sizeX; mapX++) {
            SDL_Rect blockRect = {mapX * BLOCKSIZE + renderX, mapY * BLOCKSIZE + renderY, BLOCKSIZE, BLOCKSIZE };
            Block blockId = map.at(mapY).at(mapX);
            switch(blockId) {
                case AIR:
                    spritesheet.select_sprite(7, 1);
                    spritesheet.draw_selected_sprite(&blockRect);
                    break;
                case WALL:
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
                case START:
                    spritesheet.select_sprite(0, 0);
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
        printf("\n");
    }
}

void World::level_load(const char *path) {
    inFile.open(path);
    if(!inFile) {
        std::cout << "Unable to load level";
        exit(1);
    }
    Block block;
    std::vector<Block> row;
    int blockId;
    std::string line;
    while(getline(inFile, line)) {
        std::istringstream ss(line);
        while(ss >> blockId) {
            if(blockId == 0) row.push_back(AIR);
            if(blockId == 1) row.push_back(WALL);
            if(blockId == 2) row.push_back(DIRT);
            if(blockId == 3) row.push_back(ROCK);
            if(blockId == 4) row.push_back(LAVA);
            if(blockId == 5) row.push_back(START);
            if(blockId == 6) row.push_back(FINISH);
            if(blockId == 7) row.push_back(DIAMOND);
        }
        map.push_back(row);
        row.clear();
    }
    inFile.close();
}

void World::level_unload() {
    map.clear();
}

void World::load_block_textures() {
    spritesheet = Spritesheet(renderer, "../resources/sprites.png", 8, 10);
}

void World::move_camera_to_player() {

}