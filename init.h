#ifndef INIT_H
#define INIT_H

#include <SDL.h>

bool init();
void showUntilQuit();
void close();
SDL_Surface* loadImg();
bool loadMedia();

#endif // INIT_H
