#include "Game.h"
#include "gVar.h"
#include "menu.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <ctime>
#include <cstring>

int main(int argc, char* argv[]){
    init();
    SDL_RenderCopy( getRenderer(), getTexture(), NULL, NULL);
    Menu t;
    t.showMenu();

    bool play = false;
    SDL_Event e;
    while( !play ){
        while( SDL_PollEvent( &e ) != 0 ){
            if( e.type == SDL_QUIT )
                return 0;
            int x, y;
            SDL_GetMouseState(&x, &y);
            std::cout << x << " " << y << '\n';
            // play button
            if(x > 340 && x < 574 && y > 360 && y < 408){
                if(e.type == SDL_MOUSEBUTTONDOWN)
                    play = true;
            }
            // quit button
            if(x > 340 && x < 574 && y > 520 && y < 568){
                if(e.type == SDL_MOUSEBUTTONDOWN)
                    return 0;
            }
         }
    }

//    waitUntilKeyPressed();

    int count_down = 3;
    do{
        SDL_RenderClear(getRenderer());
        drawBoard();
        loadText(std::to_string(count_down), {255, 255, 255}, {350, 300, 200, 200});
        SDL_RenderPresent(getRenderer());
        SDL_Delay(1000);
    }while(count_down--);

    srand(time(NULL));
    initBlock();

    while(!Game_over && !get_status()){
        runGame();
        for(int i = 0; i < 10; i++)
            if(matrix_board_value(0, i) > 0)
                Game_over = true;
//        std::cout << Game_over << '\n';
    }
    std::cout << "Game over";
//    SDL_Delay(10000);
    close();

    return 0;
}
