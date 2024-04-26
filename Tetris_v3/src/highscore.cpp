#include "highscore.h"

void show_cur_score(){
    // Draw
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
    // press home or quit
    bool press = false;
    go_back = false;
    SDL_Event e;
    while( !press ){
        while( SDL_PollEvent( &e ) != 0 ){
            if( e.type == SDL_QUIT )
                return;
            int x, y;
            SDL_GetMouseState(&x, &y);
            std::cout << x << " " << y << '\n';
            // 416 502 478 563
            // home button
            if(x > 416 && x < 478 && y > 502 && y < 563){
                if(e.type == SDL_MOUSEBUTTONDOWN){
                    go_back = true;
                    return;
                }
            }

        }
    }
}

void show_highscore(){
    SDL_SetRenderDrawColor(getRenderer(), 0, 0, 0, 0);
    SDL_Rect full = {0, 0, 900, 900};
    SDL_RenderFillRect(getRenderer(), &full);
    loadText("HIGH SCORES", {4, 252, 220, 255}, {280, 50, 350, 150});
    loadText("Rank", {252, 252, 4, 255}, {200, 190, 120, 80});
    loadText("Score", {252, 252, 4, 255}, {450, 190, 120, 80});
    for(int i = 1; i <= 5; i++)
        loadText(std::to_string(i), {12, 212, 36, 255}, {230, 190+i*80, 50, 80});
//    loadText("Name", {252, 252, 4, 255}, {300, 190, 120, 80});
    SDL_Rect goBack = {20, 20, 40, 40};
    SDL_RenderCopy(getRenderer(), getGoBack(), NULL, &goBack);

    SDL_RenderPresent(getRenderer());


    // high score
    std::vector<int> high_score(5, 0);
    std::fstream file;

    // read old score
    file.open("src/highscore.txt", std::ios::in);
    int temp;
    while(file >> temp)
        high_score.push_back(temp);
    file.close();
    std::sort(high_score.begin(), high_score.end(), std::greater<int>());
    // rewrite top 5 score
    file.open("src/highscore.txt", std::ios::trunc);
    for(int i = 0; i < 5; i++)
        file << high_score[i] << '\n';
    file.close();
    // render score to screen
    for(int i = 0; i < 5; i++)
        loadText(std::to_string(high_score[i]), {255, 0, 0, 255}, {450, 190+(i+1)*80, std::to_string(high_score[i]).size()*20+30, 80});
    SDL_RenderPresent(getRenderer());

    // check if press go back
    // or quit game
    go_back = false;
    SDL_Event e;
    while( !go_back ){
        while( SDL_PollEvent( &e ) != 0 ){
            if( e.type == SDL_QUIT )
                return;
            int x, y;
            SDL_GetMouseState(&x, &y);
            std::cout << x << " " << y << '\n';
            // 20 20 60 60
            if(x > 20 && x < 60 && y > 20 && y < 60){
                if(e.type == SDL_MOUSEBUTTONDOWN){
                    go_back = true;
                    return;
                }
            }
        }
    }
}

bool isTurnBack(){
    return go_back;
}
