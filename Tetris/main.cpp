#include "Game.h"
#include "gVar.h"
#include <iostream>
#include <ctime>

int main(int argc, char* argv[]){
    init();
    srand(time(NULL));
//    Block T;
//    //    T.loadTexture(getRenderer());
//
//    shape blocks[7];
//    make_block(blocks);
//
//
//    SDL_Event e; bool quit = false;
//    while(!quit){
//        while(SDL_PollEvent(&e) != 0){
//            if(e.type == SDL_QUIT)
//                quit = true;
////            drawBoard();
//            loadBoard();
//            showBoard();
//            SDL_SetRenderDrawColor(getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
//
//            for(int i = 1; i <= 10; i++)
//                T.render(276+35*i, 81+35, T.get_Block_clips('Z'));
//
//            SDL_RenderPresent(getRenderer());
//        }
//    }
    initBlock();
    loadBoard();

    while(true){
//        loadBoard();
//        showBoard();
//        SDL_RenderPresent(getRenderer());
        runGame();
    }

    close();

    return 0;
}
