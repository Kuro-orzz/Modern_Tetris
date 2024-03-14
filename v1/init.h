#ifndef INIT_H
#define INIT_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

void init();
SDL_Surface* loadImg(std::string);
void loadMedia();
void showUntilQuit();
void close();

#endif // INIT_H
