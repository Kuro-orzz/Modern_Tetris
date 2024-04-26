#include "level.h"

Oxy p[21];

void show_all_level(){
    SDL_RenderCopy(getRenderer(), getChooseLevel(), NULL, NULL);
    // draw
    int number = 0;
    SDL_SetRenderDrawColor(getRenderer(), 255, 255, 255, 255);
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 3; j++){
            SDL_Rect pos = {160+j*210, 220 + 80*i, 160, 50};
            for(int k = 0; k < 3; k++){
                SDL_Rect tmp = pos;
                tmp.x+=k; tmp.y+=k;
                tmp.w -= 2*k; tmp.h -= 2*k;
                SDL_RenderDrawRect(getRenderer(), &tmp);
            }
            SDL_Rect text = pos;
            text.x += 50; text.y += 10;
            text.w = 80; text.h = 55;
            loadText("level "+std::to_string(number), {255, 255, 255, 255}, pos);
            p[number] = {pos.x, pos.y, pos.w, pos.h};
            number++;
        }
    }
    SDL_Rect goBack = {20, 20, 40, 40};
    SDL_RenderCopy(getRenderer(), getGoBack(), NULL, &goBack);
    SDL_RenderPresent(getRenderer());
//    for(int i = 0; i < 21; i++)
//        std::cout << p[i].x << " " << p[i].y << " " << p[i].w << " " << p[i].h << '\n';

//    SDL_Delay(100000);
}

int choose_level(){
    show_all_level();
    bool choose = false;
    go_back = false;
    SDL_Event e;
    while( !choose ){
        while( SDL_PollEvent( &e ) != 0 ){
            if( e.type == SDL_QUIT )
                return -1;
            int x, y;
            SDL_GetMouseState(&x, &y);
//            std::cout << x << " " << y << '\n';
            // 20 20 60 60
            if(x > 20 && x < 60 && y > 20 && y < 60){
                if(e.type == SDL_MOUSEBUTTONDOWN){
                    go_back = true;
                    return 0;
                }
            }
            int cnt = -1;
            for(int i = 0; i < 21; i++)
                if(x > p[i].x && x < p[i].x+p[i].w && y > p[i].y && y < p[i].y+p[i].h){
                    cnt = i;
                    break;
                }
            if(cnt != -1){
                SDL_Rect pos = {p[cnt].x, p[cnt].y, p[cnt].w, p[cnt].h};
                SDL_SetRenderDrawColor(getRenderer(), 255, 255, 255, 255);
                SDL_RenderFillRect(getRenderer(), &pos);
                SDL_Rect text = pos;
                text.x += 50; text.y += 10;
                text.w = 80; text.h = 55;
                loadText("level "+std::to_string(cnt), {255, 94, 94, 255}, pos);
                SDL_RenderPresent(getRenderer());
                if(e.type == SDL_MOUSEBUTTONDOWN)
                    return cnt;
            }
            else{
                show_all_level();
            }

//            std::cout << cnt << '\n';
//            if()
        }
    }
}

bool isBackInLevel(){
    return go_back;
}
