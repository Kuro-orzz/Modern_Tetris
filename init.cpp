#include "init.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;

const int SCR_W = 900;
const int SCR_H = 900 ;
SDL_Window* gwindow = NULL;
SDL_Surface* gsurface = NULL, *gcur_surface = NULL;
SDL_Surface* gPNGSurface = NULL;
SDL_Renderer* gRenderer = NULL;

bool init(){
    if(SDL_Init(SDL_INIT_VIDEO) == -1) {cout << "Error init";return false;}
    // Check init window
    gwindow = SDL_CreateWindow("testing", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCR_W, SCR_H, SDL_WINDOW_SHOWN);
    if(!gwindow) {cout << "Error init window";return false;}
    // Check render
    gRenderer = SDL_CreateRenderer(gwindow, -1, SDL_RENDERER_ACCELERATED);
    if(!gRenderer) {cout << "Error render";return false;}
    // Check imgage
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    int imgFlags = IMG_INIT_PNG;
    if(!(IMG_Init(imgFlags) & imgFlags)) {cout << "Error init img";return false;}
    // Check surface
    gsurface = SDL_GetWindowSurface(gwindow);
    if(!gsurface) {cout << "Error get window surface";return false;}
    return true;
}

void showUntilQuit(){
    SDL_Event e; bool quit = false;
    while(!quit){
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT)
                quit = true;
            SDL_BlitSurface(gPNGSurface, NULL, gsurface, NULL );
            SDL_UpdateWindowSurface( gwindow );
        }
    }
}

void close(){
    SDL_FreeSurface(gsurface);
    gsurface = NULL;
    SDL_FreeSurface(gcur_surface);
    gcur_surface = NULL;
    SDL_DestroyWindow(gwindow);
    gwindow = NULL;
    SDL_Quit;
    IMG_Quit;
}

SDL_Surface* loadImg(string path){
    SDL_Surface* optimize = NULL;
    SDL_Surface* img = IMG_Load(path.c_str());
    if(!img)
        cout << "Error loadImg: " << IMG_GetError;
    else{
        optimize = SDL_ConvertSurface(img, gsurface->format, 0);
        if(!optimize)
            cout << "Error optimize" << SDL_GetError;
        SDL_FreeSurface(img);
    }
    return optimize;
}

bool loadMedia(){
	gPNGSurface = loadImg("board.png");
	if(gPNGSurface == NULL){
		cout << "Fail loadMedia";
		return false;
	}
	return true;
}
