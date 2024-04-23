#include "menu.h"

Menu::Menu(){
    texture = NULL;
}

Menu::~Menu(){

}

void Menu::loadMenu(){
    texture = IMG_LoadTexture(getRenderer(), "img_src/menu.png");
}

void Menu::showMenu(){
    loadMenu();
    SDL_RenderCopy(getRenderer(), texture, NULL, NULL);
    SDL_RenderPresent(getRenderer());
}
