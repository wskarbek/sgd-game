#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

class Spritesheet {
    private:
        SDL_Rect spriteClip;
        SDL_Surface * spritesheetSurface;
        SDL_Texture * spritesheetTexture;
        SDL_Renderer * spritesheetRenderer;

    public:
    Spritesheet() {}
    Spritesheet(SDL_Renderer * r, const char *path, int row, int column) {
        spritesheetRenderer = r;
        spritesheetSurface = IMG_Load(path);
        spritesheetTexture = SDL_CreateTextureFromSurface(spritesheetRenderer, spritesheetSurface);

        spriteClip.w = spritesheetSurface->w / column;
        spriteClip.h = spritesheetSurface->h / row;
    }
    
    ~Spritesheet() {
        SDL_FreeSurface(spritesheetSurface);
    }

    void select_sprite(int x, int y) {
        spriteClip.x = x * spriteClip.w;
        spriteClip.y = y * spriteClip.h;
    }

    void draw_selected_sprite(SDL_Rect* position) {
        SDL_RenderCopy(spritesheetRenderer, spritesheetTexture, &spriteClip, position);
    }
};