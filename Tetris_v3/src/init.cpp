#include "init.h"

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
TTF_Font* gFont = NULL;
SDL_Texture* background = NULL;

void init(){
    gWindow = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCR_W, SCR_H, SDL_WINDOW_SHOWN);
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    gFont = TTF_OpenFont( "lazy.ttf", 28 );
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    background = IMG_LoadTexture(getRenderer(), "img_src/background0.jpg");
    SDL_SetTextureAlphaMod(background, 0);

//    SDL_RenderCopy( gRenderer, background, NULL, NULL);
//
//    SDL_RenderPresent( gRenderer );
//    SDL_Delay(2000);
//    SDL_RenderClear(gRenderer);


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

SDL_Texture* getTexture(){
    return background;
}
