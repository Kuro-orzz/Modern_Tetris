#include "init.h"
#include "board.h"
#include "block.h"
#include "piece.h"
#include "rotation.h"

int main(int argc, char* argv[]){
    //run();
    init();
    loadBoard();

    Block T;
//    T.loadTexture(getRenderer());

    shape blocks[7];
    make_block(blocks);

    SDL_Event e; bool quit = false;
    while(!quit){
        while(SDL_PollEvent(&e) != 0){
            if(e.type == SDL_QUIT)
                quit = true;
            drawBoard();
            SDL_SetRenderDrawColor(getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);

            for(int i = 1; i <= 10; i++)
                T.render(276+35*i, 81+35, T.get_Block_clips('Z'));

            SDL_RenderPresent(getRenderer());
        }
    }



    return 0;
}
