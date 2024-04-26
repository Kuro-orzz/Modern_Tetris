#include "highscore.h"

void show_highscore(){
    SDL_SetRenderDrawColor(getRenderer(), 0, 0, 0, 0);
    SDL_Rect full = {0, 0, 900, 900};
    SDL_RenderFillRect(getRenderer(), &full);
    loadText("HIGH SCORES", {4, 252, 220, 255}, {280, 50, 350, 150});
    loadText("Rank", {252, 252, 4, 255}, {100, 150, 150, 100});

    SDL_RenderPresent(getRenderer());
    SDL_Delay(4000);
}
