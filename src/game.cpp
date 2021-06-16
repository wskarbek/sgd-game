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

void Game::nextLevel(int level) {
    world.load_block_textures();
    world.level_load("../resources/levels/2.lvl");
    SDL_Rect pos = world.player_get_position();
    player.x = pos.x;
    player.y = pos.y;
}

void Game::update() {
    if(player.moveFreeze <= 0) {
        if (state[SDL_SCANCODE_RIGHT]) {
            auto nextBlock = world.player_check_next_block(player.x, player.y, RIGHT);
            if(nextBlock != BLOCK) {
                player.x++;
                player.moveFreeze = MOVE_FREEZE;
            }
        } else
        if (state[SDL_SCANCODE_LEFT]) {
            auto nextBlock = world.player_check_next_block(player.x, player.y, LEFT);
            if(nextBlock != BLOCK) {
                player.x--;
                player.moveFreeze = MOVE_FREEZE;
            }
        } else
        if (state[SDL_SCANCODE_UP]) {
            auto nextBlock = world.player_check_next_block(player.x, player.y, UP);
            if(nextBlock != BLOCK) {
                player.y--;
                player.moveFreeze = MOVE_FREEZE;
            }
        } else
        if (state[SDL_SCANCODE_DOWN]) {
            auto nextBlock = world.player_check_next_block(player.x, player.y, DOWN);
            if(nextBlock != BLOCK) {
                player.y++;
                player.moveFreeze = MOVE_FREEZE;
            }
        }
    }
    player.moveFreeze--;
    if(physicsFreeze <= 0) {
        world.objects_move(player.x, player.y);
        physicsFreeze = PHYSICS_FREEZE;
    }
    physicsFreeze--;
}

void Game::render() {
    world.move_camera_to_player(player.x, player.y);
    world.render_world();
    world.player_render(player.x, player.y);
}