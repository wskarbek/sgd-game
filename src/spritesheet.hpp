#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Spritesheet {
    public:
        Spritesheet();
        Spritesheet(SDL_Renderer * r, const char *path, int row, int column);
        ~Spritesheet();

        void select_sprite(int x, int y);
        void draw_selected_sprite(SDL_Rect* position);

    private:
        SDL_Rect     spriteClip;
        SDL_Surface * spritesheetSurface;
        SDL_Texture * spritesheetTexture;
        SDL_Renderer * spritesheetRenderer;
};