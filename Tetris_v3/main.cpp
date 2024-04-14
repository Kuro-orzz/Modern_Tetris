#include "Game.h"
#include "gVar.h"
#include <iostream>
#include <ctime>

int main(int argc, char* argv[]){
    init();
    srand(time(NULL));
    initBlock();
//    while(true){
//        drawBoard();
//        SDL_RenderPresent(getRenderer());
//    }

    while(!Game_over){
        runGame();
        for(int i = 0; i < 10; i++)
            if(matrix_board_value(0, i) > 0)
                Game_over = true;
    }
    std::cout << "Game over";
    close();

    return 0;
}
