#ifndef BLOCK_H
#define BLOCK_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
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
        SDL_Rect get_Block_clips(int num_shape);
};

struct shape {
     SDL_Color color;
     std::vector<std::vector<int>> matrix;
     double x, y;
     int size;
     shape operator=(const shape& s);
};

void make_block(shape blocks[]);

#endif // BLOCK_H
