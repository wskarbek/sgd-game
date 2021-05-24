#include "spritesheet.hpp"

Spritesheet::Spritesheet() {}

Spritesheet::Spritesheet(SDL_Renderer * r, const char *path, int row, int column) {
    spritesheetRenderer = r;
    spritesheetSurface = IMG_Load(path);
    spritesheetTexture = SDL_CreateTextureFromSurface(r, spritesheetSurface);

    spriteClip.w = spritesheetSurface->w / column;
    spriteClip.h = spritesheetSurface->h / row;
}

Spritesheet::~Spritesheet() {
    SDL_FreeSurface(spritesheetSurface);
}

void Spritesheet::select_sprite(int x, int y) {
    spriteClip.x = x * spriteClip.w;
    spriteClip.y = y * spriteClip.h;
}

void Spritesheet::draw_selected_sprite(SDL_Rect* position) {
    SDL_RenderCopy(spritesheetRenderer, spritesheetTexture, &spriteClip, position);
}