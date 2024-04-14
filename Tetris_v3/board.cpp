#include "board.h"

void drawBoard(){
    SDL_SetRenderDrawColor(getRenderer(), 0xFF, 0xFF, 0xFF, 55);
    // Column
    for(int i = 0; i < 11; i++)
        SDL_RenderDrawLine(getRenderer(), 275+35*i, 100, 275+35*i, 800);
    // Row
    for(int i = 0; i < 21; i++)
        SDL_RenderDrawLine(getRenderer(), 275, 100+35*i, 275+350, 100+35*i);
    // make edge column
    for(int i = 0; i < 4; i++)
        SDL_RenderDrawLine(getRenderer(), 275-i, 100, 275-i, 800);
    for(int i = 0; i < 4; i++)
        SDL_RenderDrawLine(getRenderer(), 275+35*10+i, 100, 275+35*10+i, 800);
    // make edge bottom
    for(int i = 0; i < 4; i++)
        SDL_RenderDrawLine(getRenderer(), 275-3, 100+35*20+i, 275+350+3, 100+35*20+i);
    // hold
    for(int i = 0; i < 29; i++)
        SDL_RenderDrawLine(getRenderer(), 275-178, 100+i, 275, 100+i);
    for(int i = 0; i < 4; i++)
        SDL_RenderDrawLine(getRenderer(), 275-160, 100+104+i+28, 275, 100+104+i+28);
    for(int i = 0; i < 4; i++)
        SDL_RenderDrawLine(getRenderer(), 275-178+i, 100+28, 275-178+i, 100+28+90);
    for(int i = 0; i < 5; i++)
        SDL_RenderDrawLine(getRenderer(), 275-178+i, 100+90+28, 275-160-1, 100+104+28+3-i);
    // next
    for(int i = 0; i < 29; i++)
        SDL_RenderDrawLine(getRenderer(), 275+35*10, 100+i, 275+35*10+182, 100+i);
    for(int i = 0; i < 4; i++)
        SDL_RenderDrawLine(getRenderer(), 275+35*10, 100+35*20-145+i, 275+35*10+182-18-1, 100+35*20-145+i);
    for(int i = 0; i < 4; i++)
        SDL_RenderDrawLine(getRenderer(), 275+35*10+182+i-3, 100+28, 275+35*10+182+i-3, 100+35*20-145-18+1);
    for(int i = 0; i < 5; i++)
        SDL_RenderDrawLine(getRenderer(), 275+35*10+182-18-1, 100+35*20-145+i-1, 275+35*10+182+i-3-1, 100+35*20-145-18+2);
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
        if(x >= 0 && (y == 0 || matrix_board[x][y-1] > 0))
            return false;
        if(x < 0 && y == 0)
            return false;
    }
    return true;
}

bool check_collision_right(std::vector<std::pair<int, int>> &pre){
    for(int i = 0; i < pre.size(); i++){
        int x = (pre[i].second-100)/35;
        int y = (pre[i].first-275)/35;
        if(x >= 0 && (y == 9 || matrix_board[x][y+1] > 0))
            return false;
        if(x < 0 && y == 9)
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

void change_board(int x, int y, int num){
    matrix_board[x][y] = num;
}
