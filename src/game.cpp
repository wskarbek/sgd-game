#include "game.hpp"

Game::Game(SDL_Renderer * r) {
    renderer = r;
}

Game::~Game() {
    world.level_unload();
}

void Game::init() {
    world = World(renderer);
    world.load_block_textures();
    world.level_load("../resources/levels/1.lvl");
    SDL_Rect pos = world.player_get_position();
    player.x = pos.x;
    player.y = pos.y;
}

void Game::update() {
    if (state[SDL_SCANCODE_RIGHT]) {
        if(!world.player_check_next_block(player.x, player.y, RIGHT)) player.x++;
    }
    if (state[SDL_SCANCODE_LEFT]) {
        if(!world.player_check_next_block(player.x, player.y, LEFT)) player.x--;
    }
    if (state[SDL_SCANCODE_UP]) {
        if(!world.player_check_next_block(player.x, player.y, UP)) player.y--;
    }
    if (state[SDL_SCANCODE_DOWN]) {
        if(!world.player_check_next_block(player.x, player.y, DOWN)) player.y++;
    }
}

void Game::render() {
    world.render_world();
    world.player_render(player.x, player.y);
}