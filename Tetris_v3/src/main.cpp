#include "Game.h"
#include "gVar.h"
#include "menu.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <ctime>

int main(int argc, char* argv[]){
    init();
//    SDL_RenderCopy( getRenderer(), getTexture(), NULL, NULL);
//    Menu t;
//    t.showMenu();
//
//    waitUntilKeyPressed();
    srand(time(NULL));
    initBlock();
//    while(true){
//        SDL_RenderCopy( getRenderer(), getTexture(), NULL, NULL);
//        SDL_RenderPresent(getRenderer());
//        SDL_RenderClear(getRenderer());
//    }

//    SDL_Texture* background = IMG_LoadTexture(gRenderer, "scr/Elaina.jpg");

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
