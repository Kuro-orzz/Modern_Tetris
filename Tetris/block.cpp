#include "block.h"

shape shape::operator=(const shape& s){
    this->color = s.color;
    this->matrix = s.matrix;
    this->x = s.x;
    this->y = s.y;
    this->size = s.size;
    return *this;
}

void make_block(shape blocks[]){
    // L Block
    blocks[0].color = {237, 133, 1};
    blocks[0].matrix = {{0,0,1,0},
                        {1,1,1,0},
                        {0,0,0,0},
                        {0,0,0,0}};
    blocks[0].x = 5; blocks[0].y = 4;
    blocks[0].size = 3;
    // Z BLOCK
    blocks[1].color = {211, 12, 37};
    blocks[1].matrix = {{1,1,0,0},
                        {0,1,1,0},
                        {0,0,0,0},
                        {0,0,0,0}};
    blocks[1].x = 5; blocks[1].y = 4;
    blocks[1].size = 3;
    // I BLOCK
    blocks[2].color = {5, 195, 195};
    blocks[2].matrix = {{0,0,0,0},
                        {1,1,1,1},
                        {0,0,0,0},
                        {0,0,0,0}};
    blocks[2].x = 5; blocks[2].y = 4;
    blocks[2].size = 4;
    // J BLOCK
    blocks[3].color = {4, 24, 208};
    blocks[3].matrix = {{1,0,0,0},
                        {1,1,1,0},
                        {0,0,0,0},
                        {0,0,0,0}};
    blocks[3].x = 5; blocks[3].y = 4;
    blocks[3].size = 3;
    // O BLOCK
    blocks[4].color = {217, 205, 4};
    blocks[4].matrix = {{1,1,0,0},
                        {1,1,0,0},
                        {0,0,0,0},
                        {0,0,0,0}};
    blocks[4].x = 5; blocks[4].y = 4;
    blocks[4].size = 2;
    // S BLOCK
    blocks[5].color = {5, 211, 5};
    blocks[5].matrix = {{0,1,1,0},
                        {1,1,0,0},
                        {0,0,0,0},
                        {0,0,0,0}};
    blocks[5].x = 5; blocks[5].y = 4;
    blocks[5].size = 3;
    // T BLOCK
    blocks[6].color = {141, 16, 191};
    blocks[6].matrix = {{0,1,0,0},
                        {1,1,1,0},
                        {0,0,0,0},
                        {0,0,0,0}};
    blocks[6].x = 5; blocks[6].y = 4;
    blocks[6].size = 3;
}

