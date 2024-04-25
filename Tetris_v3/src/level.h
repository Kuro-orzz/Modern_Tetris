#ifndef LEVEL_H
#define LEVEL_H

#include <SDL.h>
#include <SDL_image.h>
#include <utility>
#include "init.h"

struct Oxy{
    int x, y, w, h;
};

void show_all_level();
int choose_level();

#endif
