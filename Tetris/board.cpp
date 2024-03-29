#include "board.h"

const int BOARD_POS_X = /*40*/ (SCR_W-350)/2;
const int BOARD_POS_Y = /*60*/ (SCR_H-700)/2;
const int BOARD_WIDTH = 821;
const int BOARD_HEIGHT = 779;
SDL_Texture* gBoard = NULL;

void loadBoard(){
    gBoard = IMG_LoadTexture(getRenderer(), "img_src/board.png");
}

void drawBoard(){
    for(int i = 0; i < 11; i++)
        SDL_RenderDrawLine(getRenderer(), 275+35*i, 100, 275+35*i, 800);
    for(int i = 0; i < 21; i++)
        SDL_RenderDrawLine(getRenderer(), 275, 100+35*i, 275+350, 100+35*i);
}

void showBoard(){
    SDL_Rect pos = {BOARD_POS_X, BOARD_POS_Y, BOARD_WIDTH, BOARD_HEIGHT};
    SDL_RenderCopy(getRenderer(), gBoard, NULL, &pos);

//    SDL_Rect dest;
//
//	dest.x = x;
//	dest.y = y;
//	SDL_QueryTexture(gBoard, NULL, NULL, &pos.w, &pos.h);

	SDL_RenderCopy(getRenderer(), gBoard, NULL, &pos);
}
