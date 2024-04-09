#include "Game.h"

int frameCount, timerFPS, lastFrame, fps;
int num_piece = -1;
SDL_Rect rect;
std::vector<std::pair<int, int>> prePos;
void initBlock(){
    make_block(blocks);
}

bool left, right, up, down, z, x, a;

shape reverse_shape(shape s){
    shape tmp = s;
    for(int i = 0; i < s.size; i++){
        for(int j=0; j < s.size/2; j++){
            bool t = s.matrix[i][j];
            tmp.matrix[i][j] = s.matrix[i][s.size-j-1];
            tmp.matrix[i][s.size-j-1] = t;
        }
    }
    return tmp;
}

shape transpose(shape s){
    shape tmp = s;
    for(int i=0; i<s.size; i++) {
        for(int j=0; j<s.size; j++) {
            tmp.matrix[i][j] = s.matrix[j][i];
        }
    }
    return tmp;
}

void rotate_left(){
    cur = reverse_shape(transpose(cur));
}

void rotate_right(){
    for(int i = 0; i < 3; i++)
        cur = reverse_shape(transpose(cur));
}

void rotate_180(){
    for(int i = 0; i < 2; i++)
        cur = reverse_shape(transpose(cur));
}

void update() {
    if(left && check_collision_left(prePos)) cur.x--;
    if(right && check_collision_right(prePos)) cur.x++;
    if(down) cur.y++;
    if(up) rotate_right();
    if(z) rotate_left();
    if(x) rotate_right();
    if(a) rotate_180();
}

void check_move(){
    up=down=left=right=z=x=a=0;
    SDL_Event e;
    while(SDL_PollEvent(&e)) {
        if(e.type == SDL_QUIT) running=false;

        switch( e.type ){
            case SDL_KEYUP: //DOWN
                switch(e.key.keysym.sym) {
                case SDLK_LEFT: left=1; break;
                case SDLK_RIGHT: right=1; break;
                case SDLK_UP: up=1; break;
                case SDLK_DOWN: down=1; break;
                case SDLK_z: z = 1; break;
                case SDLK_x: x = 1; break;
                case SDLK_a: a = 1; break;
                case SDLK_ESCAPE: running=false; break;
            }
            update();
        }
    }
}

void drawPiece(shape s){
    drawBoard();
    for(int i=0; i<s.size; i++) {
        for(int j=0; j<s.size; j++) {
            if(s.matrix[i][j]) {
                rect.x=100+(s.x+i+4)*TILE_SIZE; rect.y=100+(s.y+j-5)*TILE_SIZE;
                fill_matrix_board(rect.x, rect.y, num_piece);
                if(rect.y >= 100+(4+16)*TILE_SIZE){
                    running = false;
                    return;
                }
                SDL_SetRenderDrawColor(getRenderer(), s.color.r, s.color.g, s.color.b, 255);
                SDL_RenderFillRect(getRenderer(), &rect);
                SDL_SetRenderDrawColor(getRenderer(), 219, 219, 219, 255);
                SDL_RenderDrawRect(getRenderer(), &rect);
                prePos.push_back({rect.x, rect.y});
            }
        }
    }
    if(!check_collision_bottom(prePos))
        running = false;
    else
        running = true;
    erasePre_matrix_board(prePos);

}

void renderPiece() {
    SDL_SetRenderDrawColor(getRenderer(), 0, 0, 0, 255);
    SDL_RenderClear(getRenderer());

    frameCount++;
    int timerFPS = SDL_GetTicks()-lastFrame;
    if(timerFPS<(1000/60)) {
        SDL_Delay((1000/60)-timerFPS);
    }
    drawPiece(cur);
}

void runGame(){
    num_piece = rand() % 7;
    cur = blocks[num_piece];
    rect.w = rect.h = TILE_SIZE;
    running = true;
    rotate_right();
    while(running) {

        lastFrame = SDL_GetTicks();
        running = false;
        SDL_RenderPresent(getRenderer());
//        SDL_Delay(500);
        if(lastFrame>=(lastTime+1000)) {
            lastTime=lastFrame;
            fps=frameCount;
            frameCount=0;
        }
        check_move();
        prePos.clear();
        renderPiece();
    }
}
