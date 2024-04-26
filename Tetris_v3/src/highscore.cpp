#include "highscore.h"

int show_cur_score(){
    SDL_SetRenderDrawColor(getRenderer(), 255, 0, 0, 255);
    SDL_Rect black_square = {300, 360, 300, 180};
    SDL_RenderFillRect(getRenderer(), &black_square);
    SDL_SetRenderDrawColor(getRenderer(), 0, 0, 0, 255);
    SDL_Rect small_square = {310, 370, 280, 160};
    SDL_RenderFillRect(getRenderer(), &small_square);
    loadText("Score", {255, 255, 255, 255}, {390, 380, 120, 50});
    loadText(std::to_string(getScore()), {255, 255, 255, 255}, {400, 430, std::to_string(getScore()).size()*20+30, 50});
    SDL_Rect home_button_pos = {390, 480, 120, 110};
    SDL_RenderCopy(getRenderer(), getHomeButton(), NULL, &home_button_pos);
    SDL_RenderPresent(getRenderer());
    bool press = false;
    SDL_Event e;
    while( !press ){
        while( SDL_PollEvent( &e ) != 0 ){
            if( e.type == SDL_QUIT )
                return -1;
            int x, y;
            SDL_GetMouseState(&x, &y);
            std::cout << x << " " << y << '\n';
            // 416 502 478 563
            // home button
            if(x > 416 && x < 478 && y > 502 && y < 563){
                if(e.type == SDL_MOUSEBUTTONDOWN)
                    return 1;
            }

        }
    }
    return 1;
}

void show_highscore(){
    SDL_SetRenderDrawColor(getRenderer(), 0, 0, 0, 0);
    SDL_Rect full = {0, 0, 900, 900};
    SDL_RenderFillRect(getRenderer(), &full);
    loadText("HIGH SCORES", {4, 252, 220, 255}, {280, 50, 350, 150});
    loadText("Rank", {252, 252, 4, 255}, {200, 190, 120, 80});
    loadText("Score", {252, 252, 4, 255}, {450, 190, 120, 80});
    for(int i = 1; i <= 5; i++)
        loadText(std::to_string(i), {12, 212, 36, 255}, {260, 190+i*80, 50, 80});
//    loadText("Name", {252, 252, 4, 255}, {300, 190, 120, 80});
    SDL_RenderPresent(getRenderer());


    // high score
    std::vector<int> high_score;
    std::fstream file("src/highscore.txt", 	std::ios::in);
    int temp;
    while(file >> temp)
        high_score.push_back(temp);
    file.close();
    high_score.push_back(getScore());
    std::sort(high_score.begin(), high_score.end(), std::greater<int>());
    for(int i = 0; i < 5; i++)
        std::cout << high_score[i] << '\n';
    file.open("src/highscore.txt", std::ios::app);
    file << getScore() << '\n';
    std::cout << high_score.size() << '\n';
    std::cout << getScore() << '\n';
    std::cout << "Game over";
    file.close();


    bool go_back = false;
    SDL_Event e;
    while( !go_back ){
        while( SDL_PollEvent( &e ) != 0 ){
            if( e.type == SDL_QUIT )
                return;
            int x, y;
            SDL_GetMouseState(&x, &y);
            std::cout << x << " " << y << '\n';
            // 416 502 478 563
            // home button


        }
    }

    SDL_RenderPresent(getRenderer());
    SDL_Delay(10000);
}
