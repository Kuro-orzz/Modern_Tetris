#include "block.h"

const int NUMBER_OF_BLOCK = 7;

Block::Block(){
//    mTexture = NULL;
    mTexture = IMG_LoadTexture(getRenderer(), "img_src/block.png");
}

Block::~Block(){
    free();
}

void Block::free(){
    if(mTexture){
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
    }
}

void Block::render(int x, int y, SDL_Rect clip){
    SDL_Rect pos = {x, y, 35, 35};
	SDL_RenderCopy(getRenderer(), mTexture, &clip, &pos);
}

SDL_Texture* Block::getBlockTexture(){
    return this->mTexture;
}

SDL_Rect Block::get_Block_clips(int num_shape){
    SDL_Rect Block_clips[7];
    Block_clips[0] = {31, 0, 31, 31};   // L ORANGE
    Block_clips[1] = {0, 0, 31, 31};    // Z RED
    Block_clips[2] = {124, 0, 31, 31};  // I LIGHT BLUE
    Block_clips[3] = {155, 0, 31, 31};  // J  BLUE
    Block_clips[4] = {62, 0, 31, 31};   // O YELLOW
    Block_clips[5] = {93, 0, 31, 31};   // S GREEN
    Block_clips[6] = {186, 0, 31, 31};  // T PURPLE
    switch(num_shape){
        case 0: return Block_clips[0];
        case 1: return Block_clips[1];
        case 2: return Block_clips[2];
        case 3: return Block_clips[3];
        case 4: return Block_clips[4];
        case 5: return Block_clips[5];
        case 6: return Block_clips[6];
    }
    return {0, 0, 0, 0};
}

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

