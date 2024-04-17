#include "init.h"

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
//SDL_Texture* background = NULL;

void init(){
    gWindow = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCR_W, SCR_H, SDL_WINDOW_SHOWN);
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

//    SDL_Texture* background = IMG_LoadTexture(gRenderer, "Elaina.jpg");
//    SDL_RenderCopy( gRenderer, background, NULL, NULL);
//
//    SDL_RenderPresent( gRenderer );

//    SDL_Texture *background = IMG_LoadTexture(gRenderer, "img_scr\Elaina.jpg");
//    SDL_RenderCopy(gRenderer, background, NULL, NULL);
////    SDL_Rect Position;
//    SDL_RenderPresent( gRenderer );
//    Position.x = 0;
//    Position.y = 0;
//    Position.w = SCR_W;
//    Position.h = SCR_H;
//    SDL_BlitScaled(scr, NULL, gScreen, &Position);
//    SDL_UpdateWindowSurface(gWindow);
}

void waitUntilKeyPressed(){
    SDL_Event e;
    while(true) {
        if(SDL_PollEvent(&e) != 0 && (e.type == SDL_KEYDOWN || e.type == SDL_QUIT))
            return;
    }
}

void close(){
    SDL_DestroyRenderer(gRenderer);
//    gRenderer = NULL;
    SDL_DestroyWindow(gWindow);
//    gWindow = NULL;
    SDL_Quit();
//    IMG_Quit();
}

SDL_Renderer* getRenderer(){
    return gRenderer;
}

SDL_Window* getWindow(){
    return gWindow;
}

//SDL_Texture* getTexture(){
//    return background;
//}
