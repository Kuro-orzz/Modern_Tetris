#include "rotation.h"

bool Can_Rotate_Right(shape cur){
    next = cur;
    for(int i = 0; i < 3; i++)
        next = reverse_shape(transpose(next));
    SDL_Rect pos;
    for(int i = 0; i < next.size; i++){
        for(int j = 0; j < next.size; j++){
            if(next.matrix[i][j]){
                pos.x = 100 + (next.x + i + 4)*35;
                pos.y = 100 + (next.y + j - 5)*35;
                int x = (pos.y-100)/35;
                int y = (pos.x-275)/35;
                if(y < 0 || y > 9)
                    return false;
                if(x > 19)
                    return false;
                if(matrix_board_value(x, y) > 0)
                    return false;
            }
        }
    }
    return true;
}

bool Can_Rotate_Left(shape cur){
    next = cur;
    next = reverse_shape(transpose(next));
    SDL_Rect pos;
    for(int i = 0; i < next.size; i++){
        for(int j = 0; j < next.size; j++){
            if(next.matrix[i][j]){
                pos.x = 100 + (next.x + i + 4)*35;
                pos.y = 100 + (next.y + j - 5)*35;
                int x = (pos.y-100)/35;
                int y = (pos.x-275)/35;
                if(y < 0 || y > 9)
                    return false;
                if(x > 19)
                    return false;
                if(matrix_board_value(x, y) > 0)
                    return false;
            }
        }
    }
    return true;
}

bool Can_Rotate_180(shape cur){
    next = cur;
    for(int i = 0; i < 2; i++)
        next = reverse_shape(transpose(next));
    SDL_Rect pos;
    for(int i = 0; i < next.size; i++){
        for(int j = 0; j < next.size; j++){
            if(next.matrix[i][j]){
                pos.x = 100 + (next.x + i + 4)*35;
                pos.y = 100 + (next.y + j - 5)*35;
                int x = (pos.y-100)/35;
                int y = (pos.x-275)/35;
                if(y < 0 || y > 9)
                    return false;
                if(x > 19)
                    return false;
                if(matrix_board_value(x, y) > 0)
                    return false;
            }
        }
    }
    return true;
}
