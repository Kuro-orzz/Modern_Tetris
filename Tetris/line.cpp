#include "line.h"

void line_clear(){
    std::vector<int> row;
    for(int i = 0; i < 20; i++){
        bool check = true;
        for(int j = 0; j < 10; j++){
            if(matrix_board_value(i, j) == 0)
                check = false;
        }
        if(check)
            row.push_back(i);
    }
    std::reverse(row.begin(), row.end());
//    std::cout << "\033[2J\033[1;1H";
//    for(int i = 0; i < 20; i++){
//        for(int j = 0; j < 10; j++)
//            std::cout << matrix_board_value(i, j);
//        std::cout << '\n';
//    }
//    for(int x : row)
//        std::cout << x << " ";
    row.push_back(-1);
    int down = 0;
    for(int i = 0; i < row.size()-1; i++){
        for(int j = row[i]; j > row[i+1]; j--){
            for(int k = 0; k < 10; k++){
                change_board(j+1, k, matrix_board_value(j, k));
            }
        }
        down++;
    }
}
