#include "Game.h"
#include "gVar.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <ctime>

int main(int argc, char* argv[]){
    init();

//    waitUntilKeyPressed();
    srand(time(NULL));
    initBlock();

    while(!Game_over){
        runGame();
        for(int i = 0; i < 10; i++)
            if(matrix_board_value(0, i) > 0)
                Game_over = true;
//        std::cout << Game_over << '\n';
    }
    std::cout << "Game over";
    SDL_Delay(10000);
    close();

    return 0;
}
