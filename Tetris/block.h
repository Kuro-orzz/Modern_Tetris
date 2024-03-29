#ifndef BLOCK_H
#define BLOCK_H

#include <SDL.h>
#include <SDL_image.h>
#include "init.h"
#include "board.h"

class Block{
    private:
        SDL_Texture* mTexture;
    public:
        Block();
        ~Block();
        void free();
        void render(int x, int y, SDL_Rect clip);
        SDL_Texture* getTexture();
//        void loadTexture(SDL_Renderer* render);
        SDL_Texture* getBlockTexture();
        SDL_Rect get_Block_clips(char shape);
};


#endif // BLOCK_H
