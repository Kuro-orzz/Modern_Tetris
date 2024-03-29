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

//void Block::loadTexture(SDL_Renderer* render){
//	this->mTexture = IMG_LoadTexture(render, "img_src/block.png");
//}

SDL_Texture* Block::getBlockTexture(){
    return this->mTexture;
}

SDL_Rect Block::get_Block_clips(char shape){
    SDL_Rect Block_clips[7];
    Block_clips[0] = {0, 0, 31, 31};    // Z RED
    Block_clips[1] = {31, 0, 31, 31};   // L ORANGE
    Block_clips[2] = {62, 0, 31, 31};   // O YELLOW
    Block_clips[3] = {93, 0, 31, 31};   // S GREEN
    Block_clips[4] = {124, 0, 31, 31};  // I LIGHT BLUE
    Block_clips[5] = {155, 0, 31, 31};  // J  BLUE
    Block_clips[6] = {186, 0, 31, 31};  // T PURPLE
    switch(shape){
        case 'Z': return Block_clips[0];
        case 'L': return Block_clips[1];
        case 'O': return Block_clips[2];
        case 'S': return Block_clips[3];
        case 'I': return Block_clips[4];
        case 'J': return Block_clips[5];
        case 'T': return Block_clips[6];
    }
    return {0, 0, 0, 0};
}



