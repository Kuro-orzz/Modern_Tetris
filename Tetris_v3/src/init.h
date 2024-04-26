#ifndef INIT_H
#define INIT_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <iostream>

const int SCR_W = 900;
const int SCR_H = 900;
//SDL_Texture* background = NULL;

void init();
void loadText(std::string s, SDL_Color color, SDL_Rect Text_pos);
void waitUntilKeyPressed();
void close();
SDL_Renderer* getRenderer();
SDL_Window* getWindow();
SDL_Texture* getTexture();
SDL_Texture*  getPauseButton();
SDL_Texture* getResume();
TTF_Font* getFont();

#endif // INIT_H
