#include "menu.h"

Menu::Menu(){
    menu = NULL;
}

Menu::~Menu(){
    SDL_DestroyTexture(menu);
}

void Menu::loadMenu(){
    menu = IMG_LoadTexture(getRenderer(), "img_src/menu.png");
}

void Menu::showMenu(){
    loadMenu();
    SDL_RenderCopy(getRenderer(), menu, NULL, NULL);
    SDL_RenderPresent(getRenderer());
}
