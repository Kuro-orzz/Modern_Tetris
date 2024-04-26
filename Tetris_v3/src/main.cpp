#include "Game.h"
#include "gVar.h"
#include "menu.h"
//#include "music.h"
#include "level.h"
#include "highscore.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <ctime>
#include <cstring>
#include <fstream>
#include <vector>

//Music* MainMusic;

int main(int argc, char* argv[]){
    init();
//    MainMusic = new Music("Sound/beat.mp3");
//    MainMusic->PlayMusic(2);
//    SDL_Delay(3000);
//    SDL_RenderCopy( getRenderer(), getTexture(), NULL, NULL);
    Menu t;
    t.loadMenu();
//    SDL_Rect button = {840, 10, 50, 50};
//    SDL_RenderCopy( getRenderer(), getPauseButton(), NULL, &button);
//    SDL_RenderPresent(getRenderer());
//    waitUntilKeyPressed();
//    t.showMenu();
//    t.showMenu();

//    SDL_SetRenderDrawColor(getRenderer(), 0, 0, 0, 255);
//    SDL_Rect playPos = {340, 360, 574-340, 408-360};
//    SDL_RenderFillRect(getRenderer(), &playPos);
//    SDL_Rect quitPos = {340, 520, 574-340, 560-520};
//    SDL_RenderFillRect(getRenderer(), &quitPos);

//    SDL_RenderPresent(getRenderer());
    int level = 0;
    int tmp = level;
    auto showMenu = [&](){
        t.showMenu();
        SDL_RenderPresent(getRenderer());
        bool play = false;
        SDL_Event e;
        while( !play ){
            while( SDL_PollEvent( &e ) != 0 ){
                if( e.type == SDL_QUIT )
                    return 0;
                int x, y;
                SDL_GetMouseState(&x, &y);
                std::cout << x << " " << y << '\n';
                //play button
                if(x > 340 && x < 574 && y > 360 && y < 408){
                    // Draw
                    SDL_SetRenderDrawColor(getRenderer(), 0, 0, 0, 255);
                    SDL_Rect playPos = {340, 360, 574-340, 410-360};
                    SDL_RenderFillRect(getRenderer(), &playPos);
                    SDL_SetRenderDrawColor(getRenderer(), 255, 255, 255, 255);
                    SDL_RenderFillRect(getRenderer(), &playPos);
                    loadText("Play", {255, 94, 94, 255}, {418, 355, 80, 60});
                    SDL_RenderPresent(getRenderer());

                    if(e.type == SDL_MOUSEBUTTONDOWN){
                        //MainMusic->PlayMusic(2);
                        // play game
                        level = 0;
                        tmp = level;
                        setScore(0);
                        setClearedLine(0);
                        play = true;
                    }
                }
                // level
                else if(x > 340 && x < 574 && y > 436 && y < 486){
                    // draw
                    SDL_SetRenderDrawColor(getRenderer(), 0, 0, 0, 255);
                    SDL_Rect playPos = {340, 436, 574-340, 486-436};
                    SDL_RenderFillRect(getRenderer(), &playPos);
                    SDL_SetRenderDrawColor(getRenderer(), 255, 255, 255, 255);
                    SDL_RenderFillRect(getRenderer(), &playPos);
                    loadText("Level", {255, 94, 94, 255}, {410, 430, 100, 60});
                    SDL_RenderPresent(getRenderer());

                    if(e.type == SDL_MOUSEBUTTONDOWN){
                        // choose level
                        level = choose_level();
                        // if quit
                        if(level == -1)
                            return 0;
                        // play level chosen
                        if(!isBackInLevel()){
                            tmp = level;
                            setScore(0);
                            setClearedLine(0);
                            play = true;
                        }
                    }
                }
               // high score
                else if(x > 340 && x < 574 && y > 516 && y < 564){
                    // draw
                    SDL_SetRenderDrawColor(getRenderer(), 0, 0, 0, 255);
                    SDL_Rect playPos = {340, 516, 574-340, 564-516};
                    SDL_RenderFillRect(getRenderer(), &playPos);
                    SDL_SetRenderDrawColor(getRenderer(), 255, 255, 255, 255);
                    SDL_RenderFillRect(getRenderer(), &playPos);
                    loadText("High score", {255, 94, 94, 255}, {360, 508, 200, 60});
                    SDL_RenderPresent(getRenderer());

                    if(e.type == SDL_MOUSEBUTTONDOWN){
                        SDL_RenderClear(getRenderer());
                        show_highscore();
                        if(!isTurnBack())
                            return 0;
                    }
                }
                // quit
                else if(x > 340 && x < 574 && y > 591 && y < 638){
                    SDL_SetRenderDrawColor(getRenderer(), 0, 0, 0, 255);
                    SDL_Rect playPos = {340, 591, 574-340, 638-591};
                    SDL_RenderFillRect(getRenderer(), &playPos);
                    SDL_SetRenderDrawColor(getRenderer(), 255, 255, 255, 255);
                    SDL_RenderFillRect(getRenderer(), &playPos);
                    loadText("Quit", {255, 94, 94, 255}, {418, 587, 80, 60});

                    SDL_RenderPresent(getRenderer());
                    if(e.type == SDL_MOUSEBUTTONDOWN)
                        return 0;

                }
                // normal menu
                else{
                    t.showMenu();
                    SDL_RenderPresent(getRenderer());
                }
             }
        }
        return 1;
    };

    auto countDown = [&](){
        int count_down = 3;
        do{
            SDL_RenderClear(getRenderer());
            drawBoard();
            loadText(std::to_string(count_down), {255, 255, 255}, {350, 300, 200, 200});
            SDL_RenderPresent(getRenderer());
            SDL_Delay(1000);
        }while(count_down--);
    };

    while(true){

        if(showMenu() == 0)
            return 0;
    //    countDown();
        srand(time(NULL));
        initBlock();
        while(!Game_over && !isQuit()){
            if(isRestart()){
                level = tmp;
                setScore(0);
                setClearedLine(0);
    //            countDown();
            }
            runGame(level);
            level = cur_level();
            for(int i = 0; i < 10; i++)
                if(matrix_board_value(0, i) > 0)
                    Game_over = true;
            if(isReturnTOMenu()){
                if(showMenu() == 0)
                    return 0;
            }
        }
        show_cur_score();
        // save score
        std::fstream file;
        file.open("src/highscore.txt", std::ios::app);
        file << getScore() << '\n';
        file.close();
        if(!isTurnBack())
            return 0;

        Game_over = false;
        setScore(0);
        setClearedLine(0);
        for(int i = 0; i < 20; i++)
            for(int j = 0; j < 10; j++)
                change_board(i, j, 0);
    }
    close();
    return 0;
}
