#include "init.h"

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
TTF_Font* gFont = NULL;
SDL_Texture* background = NULL;
SDL_Texture* choose_level_background = NULL;
SDL_Texture* Pause_button = NULL;
SDL_Texture* resume = NULL;
SDL_Texture* home_button = NULL;
SDL_Texture* go_back = NULL;

void init(){
    SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO );
    gWindow = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCR_W, SCR_H, SDL_WINDOW_SHOWN);
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();

//    if(Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 512 ))
//        std::cout << Mix_GetError();

    gFont = TTF_OpenFont("Font/VNI-Disney.ttf", 500);

    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    background = IMG_LoadTexture(gRenderer, "img_src/background0.jpg");
    choose_level_background = IMG_LoadTexture(getRenderer(), "img_src/choose_level.png");
    Pause_button = IMG_LoadTexture(gRenderer, "img_src/Pause_Button.png");
    resume = IMG_LoadTexture(gRenderer, "img_src/resume.png");
    home_button = IMG_LoadTexture(gRenderer, "img_src/home_button.png");
    go_back = IMG_LoadTexture(gRenderer, "img_src/go_back.jpg");

//    SDL_RenderCopy( gRenderer, background, NULL, NULL);
//
//    SDL_RenderPresent( gRenderer );
//    SDL_Delay(2000);
//    SDL_RenderClear(gRenderer);


}

void loadText(std::string s, SDL_Color color, SDL_Rect Text_pos){
    SDL_Surface* text = TTF_RenderText_Solid(gFont, s.c_str(), color);
    SDL_Texture* mText = SDL_CreateTextureFromSurface(gRenderer, text);

    SDL_RenderCopy(gRenderer, mText, NULL, &Text_pos);

    SDL_FreeSurface(text);
    SDL_DestroyTexture(mText);
}

void waitUntilKeyPressed(){
    SDL_Event e;
    while(true) {
        if(SDL_PollEvent(&e) != 0 && (e.type == SDL_KEYDOWN || e.type == SDL_QUIT))
            return;
    }
}

void close(){
    SDL_DestroyTexture(background);
    background = NULL;
    SDL_DestroyTexture(Pause_button);
    Pause_button = NULL;
    SDL_DestroyTexture(resume);
    resume = NULL;
    SDL_DestroyTexture(home_button);
    home_button = NULL;
    SDL_DestroyRenderer(gRenderer);
    gRenderer = NULL;
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    TTF_CloseFont( gFont );
	gFont = NULL;
    SDL_Quit();
	IMG_Quit();
	TTF_Quit();
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

SDL_Texture* getChooseLevel(){
    return choose_level_background;
}

SDL_Texture* getPauseButton(){
    return Pause_button;
}

SDL_Texture* getResume(){
    return resume;
}

SDL_Texture* getHomeButton(){
    return home_button;
}

SDL_Texture* getGoBack(){
    return go_back;
}

TTF_Font* getFont(){
    return gFont;
}
