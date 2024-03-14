#include "init.h"

const int SCR_W = 900;
const int SCR_H = 900 ;
SDL_Window* gWindow = NULL;
SDL_Surface* gSurface = NULL;
SDL_Surface* gPNGSurface = NULL;
SDL_Renderer* gRenderer = NULL;

void init(){
    gWindow = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCR_W, SCR_H, SDL_WINDOW_SHOWN);
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    gSurface = SDL_GetWindowSurface(gWindow);
}

SDL_Surface* loadImg(std::string path){
    SDL_Surface* optimize = NULL;
    SDL_Surface* img = IMG_Load(path.c_str());
    optimize = SDL_ConvertSurface(img, gSurface->format, 0);
    SDL_FreeSurface(img);
    return optimize;
}

void loadMedia(){
	gPNGSurface = loadImg("img_src/board.png");
}

void showUntilQuit(){
    SDL_Event e; bool quit = false;
    while(!quit){
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT)
                quit = true;
            SDL_Rect pos = {40, 60, 821, 779};
            SDL_BlitSurface(gPNGSurface, NULL, gSurface, &pos);
            SDL_UpdateWindowSurface(gWindow);
        }
    }
}

void close(){
    SDL_FreeSurface(gSurface);
    gSurface = NULL;
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    SDL_Quit();
    IMG_Quit();
}
