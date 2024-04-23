#ifndef MENU_H
#define MENU_H

#include <SDL.h>
#include <SDL_image.h>
#include "init.h"

class Menu{
private:
    SDL_Texture* texture;
public:
    Menu();
    ~Menu();
    void loadMenu();
    void showMenu();
};

#endif // MENU_H
