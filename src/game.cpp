#include "game.hpp"

Game::Game(SDL_Renderer * r) {
    renderer = r;
}

Game::~Game() {}

void Game::init() {
    world = World(renderer);
    world.load_block_textures();
    world.level_load("../resources/levels/1.lvl");
}

void Game::update() {
        if (state[SDL_SCANCODE_RIGHT]) {
      
        }
        if (state[SDL_SCANCODE_LEFT]) {
            
        }
        if (state[SDL_SCANCODE_UP]) {
           
        }
        if (state[SDL_SCANCODE_DOWN]) {
            
        }
}

void Game::render() {
    world.render_world();
}