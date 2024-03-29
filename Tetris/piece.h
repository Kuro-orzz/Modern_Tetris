#ifndef PIECE_H
#define PIECE_H

#include <SDL.h>
#include <vector>
#include <iostream>

struct shape {
     SDL_Color color;
     std::vector<std::vector<int>> matrix;
     double x, y;
     int size;
};

void make_block(shape blocks[]);

#endif // SHAPE_H

