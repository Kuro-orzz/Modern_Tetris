#ifndef BLOCK_H
#define BLOCK_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "init.h"

struct shape {
     SDL_Color color;
     std::vector<std::vector<int>> matrix;
     double x, y;
     int size;
     shape();
     ~shape();
     shape operator=(const shape& s);
};

void make_block(shape blocks[]);

#endif // BLOCK_H
