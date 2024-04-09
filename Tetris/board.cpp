#include "board.h"

const int BOARD_POS_X = 40; //(SCR_W-350)/2;
const int BOARD_POS_Y = 60; //(SCR_H-700)/2;
const int BOARD_WIDTH = 971;//821;
const int BOARD_HEIGHT = 1080;//779;
static int matrix_board[20][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
SDL_Texture* gBoard = NULL;

void loadBoard(){
    gBoard = IMG_LoadTexture(getRenderer(), "img_src/board_ver2.png");
}

void drawBoard(){
    SDL_SetRenderDrawColor(getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
    for(int i = 0; i < 11; i++)
        SDL_RenderDrawLine(getRenderer(), 275+35*i, 100, 275+35*i, 800);
    for(int i = 0; i < 21; i++)
        SDL_RenderDrawLine(getRenderer(), 275, 100+35*i, 275+350, 100+35*i);
}

void showBoard(){
    SDL_Rect pos = {BOARD_POS_X, BOARD_POS_Y, BOARD_WIDTH, BOARD_HEIGHT};
    SDL_RenderCopy(getRenderer(), gBoard, NULL, &pos);
	SDL_RenderCopy(getRenderer(), gBoard, NULL, &pos);
}

void fill_matrix_board(int x, int y, int num){
    x -= 275;
    y -= 100;
    matrix_board[y/35][x/35] = num;
    std::cout << "\033[2J\033[1;1H";
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 10; j++)
            std::cout << matrix_board[i][j];
        std::cout << '\n';
    }
}

void erasePre_matrix_board(std::vector<std::pair<int, int>> pre){
    for(int i = 0; i < pre.size(); i++)
        matrix_board[(pre[i].second-100)/35][(pre[i].first-275)/35] = 0;
}

bool check_collision_bottom(std::vector<std::pair<int, int>> pre){
    int bottom_piece = -1;
    for(int i = 0; i < pre.size(); i++)
        bottom_piece = std::max(bottom_piece, (pre[i].second-100)/35);
    std::cout << bottom_piece << std::endl;
    if(bottom_piece >= 19)
        return false;
    for(int i = 0; i < pre.size(); i++)
        if((pre[i].second-100)/35 == bottom_piece)
            if(matrix_board[bottom_piece+1][(pre[i].first-275)/35] > 0)
                return false;
    return true;
}

bool check_collision_left(std::vector<std::pair<int, int>> pre){
    for(int i = 0; i < pre.size(); i++)
        if((pre[i].first-275)/35 == 0)
            return false;
    return true;
}

bool check_collision_right(std::vector<std::pair<int, int>> pre){
    for(int i = 0; i < pre.size(); i++)
        if((pre[i].first-275)/35 == 9)
            return false;
    return true;
}
