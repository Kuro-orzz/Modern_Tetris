#include "board.h"

void drawBoard(){
    SDL_SetRenderDrawColor(getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
    for(int i = 0; i < 11; i++)
        SDL_RenderDrawLine(getRenderer(), 275+35*i, 100, 275+35*i, 800);
    for(int i = 0; i < 21; i++)
        SDL_RenderDrawLine(getRenderer(), 275, 100+35*i, 275+350, 100+35*i);
}

void fill_matrix_board(int x, int y, int num){
    x -= 275;
    y -= 100;
    matrix_board[y/35][x/35] = num;
//    std::cout << "\033[2J\033[1;1H";
//    for(int i = 0; i < 20; i++){
//        for(int j = 0; j < 10; j++)
//            std::cout << matrix_board[i][j];
//        std::cout << '\n';
//    }
}

void erasePre_matrix_board(std::vector<std::pair<int, int>> &pre){
    for(int i = 0; i < pre.size(); i++)
        matrix_board[(pre[i].second-100)/35][(pre[i].first-275)/35] = 0;
}

bool check_collision_bottom(std::vector<std::pair<int, int>> &pre){
    std::vector<int> bottom_piece(10, -1);
    for(int i = 0; i < pre.size(); i++){
        int x = (pre[i].second-100)/35;
        int y = (pre[i].first-275)/35;
        bottom_piece[y] = std::max(bottom_piece[y], x);
    }
    for(int i = 0; i < 10; i++){
        if(bottom_piece[i] != -1 && matrix_board[bottom_piece[i]+1][i] > 0)
            return false;
        if(bottom_piece[i] >= 19)
            return false;
    }
    return true;
}

bool check_collision_left(std::vector<std::pair<int, int>> &pre){
    for(int i = 0; i < pre.size(); i++){
        int x = (pre[i].second-100)/35;
        int y = (pre[i].first-275)/35;
        if(y == 0 || matrix_board[x][y-1] > 0)
            return false;

    }
    return true;
}

bool check_collision_right(std::vector<std::pair<int, int>> &pre){
    for(int i = 0; i < pre.size(); i++){
        int x = (pre[i].second-100)/35;
        int y = (pre[i].first-275)/35;
        if(y == 9 || matrix_board[x][y+1] > 0)
            return false;
    }
    return true;
}

int matrix_board_value(int x, int y){
    return matrix_board[x][y];
}

void display_block(const shape blocks[]){
    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 10; j++){
            int num_shape = matrix_board[i][j];
            if(num_shape > 0){
                SDL_Rect pos;
                pos.x = 275+j*35;
                pos.y = 100+i*35;
                pos.w = 35; pos.h = 35;
                Uint8 r, g, b;
                r = blocks[num_shape-1].color.r;
                g = blocks[num_shape-1].color.g;
                b = blocks[num_shape-1].color.b;
                SDL_SetRenderDrawColor(getRenderer(), r, g, b, 255);
                SDL_RenderFillRect(getRenderer(), &pos);
                SDL_SetRenderDrawColor(getRenderer(), 219, 219, 219, 255);
                SDL_RenderDrawRect(getRenderer(), &pos);
            }
        }
}

void hardDrop(std::vector<std::pair<int, int>> &pre){

}
