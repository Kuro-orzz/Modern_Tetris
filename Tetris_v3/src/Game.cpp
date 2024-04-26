#include "Game.h"

int timerFPS, currentTime, lastTime, delta;
int num_piece = -1;
SDL_Rect rect;
std::vector<std::pair<int, int>> prePos;
//std::set<int> seven_bag_system;
bool left, right, up, down, z, x, a, hard_drop, c, quit_game = false;
int drop = 0;
bool used_hold = false;

void initBlock(){
    make_block(blocks);
}

int random_piece(){
    if(next_piece.size() == 0){
        for(int i = 0; i < 6; i++){
            int tmp = rand() % 7;
            while(seven_bag_system.find(tmp) != seven_bag_system.end())
                tmp = rand() % 7;
            seven_bag_system.insert(tmp);
            next_piece.push_back(tmp);
        }
        num_piece = next_piece.back();
        next_piece.pop_back();
    }
    else{
        num_piece = next_piece.back();
        next_piece.pop_back();
        int tmp = rand() % 7;
        if(seven_bag_system.size() == 7)
            seven_bag_system.clear();
        while(seven_bag_system.find(tmp) != seven_bag_system.end())
            tmp = rand() % 7;
        seven_bag_system.insert(tmp);
        next_piece.insert(next_piece.begin(), tmp);
    }
}

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

void hold_shape(){
    if(used_hold)
        return;
    if(!isHold){
        hold_piece_num = num_piece;
        hold = blocks[num_piece];
        isHold = true;
        running = false;
    }
    else{
        cur = hold;
        hold = blocks[num_piece];
        std::swap(num_piece, hold_piece_num);
    }
    for(int i = 0; i < 3; i++)
        hold = reverse_shape(transpose(hold));
    used_hold = true;
}

void draw_hold_shape(){
    //draw
    SDL_Rect pos;
    for(int i=0; i<hold.size; i++) {
        for(int j=0; j<hold.size; j++) {
            if(hold.matrix[i][j]) {
                pos.x = (hold.x+i+4)*TILE_SIZE - 190;
                pos.y = 170 + (hold.y+j-5)*TILE_SIZE;
                pos.x += (hold.size == 2 ? 30:0) + (hold.size == 3 ? 10:0) + (hold.size == 4 ? -7:0);
                pos.y += (hold.size == 2 ? 10:0) + (hold.size == 3 ? 10:0) + (hold.size == 4 ? -5:0);
                pos.w = TILE_SIZE;
                pos.h = TILE_SIZE;
                SDL_SetRenderDrawColor(getRenderer(), hold.color.r, hold.color.g, hold.color.b, 255);
                SDL_Rect tmp = pos;
                tmp.x++; tmp.y++;
                tmp.w -= 2; tmp.h -= 2;
                SDL_RenderFillRect(getRenderer(), &tmp);
                SDL_SetRenderDrawColor(getRenderer(), 219, 219, 219, 255);
                SDL_RenderDrawRect(getRenderer(), &tmp);
            }
        }
    }
}

void draw_next_piece(){
    for(int k = 0; k < 5; k++){
        SDL_Rect pos;
        shape next = blocks[next_piece[k]];
        for(int i = 0; i < 3; i++)
            next = reverse_shape(transpose(next));
        for(int i=0; i<next.size; i++) {
            for(int j=0; j<next.size; j++) {
                if(next.matrix[i][j]) {
                    pos.x = (next.x+i+4)*TILE_SIZE + 340;
                    pos.y = (next.y+j-5)*TILE_SIZE + 3*(5-k)*35 + 70;
                    pos.x += (next.size == 2 ? 30:0) + (next.size == 3 ? 10:0) + (next.size == 4 ? -7:0);
                    pos.y += (next.size == 2 ? 10:0) + (next.size == 3 ? 10:0) + (next.size == 4 ? -5:0);
                    pos.w = TILE_SIZE;
                    pos.h = TILE_SIZE;
                    SDL_SetRenderDrawColor(getRenderer(), next.color.r, next.color.g, next.color.b, 255);
                    SDL_Rect tmp = pos;
                    tmp.x++; tmp.y++;
                    tmp.w -= 2; tmp.h -= 2;
                    SDL_RenderFillRect(getRenderer(), &tmp);
                    SDL_SetRenderDrawColor(getRenderer(), 219, 219, 219, 255);
                    SDL_RenderDrawRect(getRenderer(), &tmp);
                }
            }
        }
    }
}

int hardDrop(std::vector<std::pair<int, int>> &pre){
    int stop = 100;
    std::vector<int> col(10, -2);
    for(int i = 0; i < pre.size(); i++){
        int x = (pre[i].second-100)/35;
        int y = (pre[i].first-275)/35;
        col[y] = std::max(col[y], x);
    }
    for(int i = 0; i < 10; i++){
        if(col[i] != -2){
            int tmp = 0;
            while(col[i] < 19 && matrix_board_value(col[i]+1, i) == 0){
                col[i]++;
                tmp++;
            }
            stop = std::min(stop, tmp);
        }
    }
    return stop;
}

void ghost_block(shape s){
    for(int i=0; i<s.size; i++) {
        for(int j=0; j<s.size; j++) {
            if(s.matrix[i][j]) {
                rect.x=100+(s.x+i+4)*TILE_SIZE;
                rect.y=100+(s.y+hardDrop(prePos)+j-5)*TILE_SIZE;
                SDL_SetRenderDrawColor(getRenderer(), s.color.r, s.color.g, s.color.b, 255);
                SDL_Rect pos = rect;
                pos.x += 1; pos.y += 1;
                pos.w = pos.h -= 2;
                SDL_RenderDrawRect(getRenderer(), &pos);
            }
        }
    }
}

void update() {
    // arrow
    if(left && check_collision_left(prePos)) cur.x--;
    if(right && check_collision_right(prePos)) cur.x++;
    if(down && check_collision_bottom(prePos)) cur.y++;
    //rotate right
    if((up || x) && Can_Rotate_Right(cur)) rotate_right();
    // rotate left
    if(z && Can_Rotate_Left(cur)) rotate_left();
    //rotate 180
    if(a && Can_Rotate_180(cur)) rotate_180();
    // hard drop
    if(hard_drop) cur.y += hardDrop(prePos);
    // hold
    if(c) hold_shape();
}

void check_move(){
    up = down = left = right = z = x = a = hard_drop = c = 0;
    SDL_Event e;
    while(SDL_PollEvent(&e)) {
        if(e.type == SDL_QUIT){running = false; quit_game = true; return;}
        // 840, 10, 50, 50
        int x, y;
        SDL_GetMouseState(&x, &y);
        if(((x > 840 && x < 890 && y > 10 && y < 60) && e.type == SDL_MOUSEBUTTONDOWN) || (e.type == SDLK_ESCAPE)){
            bool press = false;
            SDL_Event e;
            while( !press ){
                while( SDL_PollEvent( &e ) != 0 ){
                    if( e.type == SDL_QUIT ){running = false; quit_game = true; return;}
                        int x, y;
                        SDL_GetMouseState(&x, &y);
                        std::cout << x << " " << y << '\n';
                        SDL_Rect pos = {300, 200, 400, 468};
                        SDL_RenderCopy(getRenderer(), getResume(), NULL, &pos);
                        SDL_RenderPresent(getRenderer());
                        // 345 581 652 639
                        // back to game
                        if(x > 345 && x < 652 && y > 581 && y < 639){
                            if(e.type == SDL_MOUSEBUTTONDOWN)
                                press = true;
                        }
                        // 407 478 596 507
                        // restart
                        else if(x > 407 && x < 596 && y > 478 && y < 507){
                            if(e.type == SDL_MOUSEBUTTONDOWN){
                                for(int i = 0; i < 20; i++)
                                    for(int j = 0; j < 10; j++)
                                        change_board(i, j, 0);
                                running = false;
                                restart = true;
                                return;
                            }
                        }
                        // 407 519 596 551
                        // return to menu
                        else if(x > 407 && x < 596 && y > 519 && y < 551){
//                            std::cout << running << '\n';
                            if(e.type == SDL_MOUSEBUTTONDOWN){
                                return_to_menu = true;
                                for(int i = 0; i < 20; i++)
                                    for(int j = 0; j < 10; j++)
                                        change_board(i, j, 0);
                                running = false;
                                return;
                            }
                        }
//                        std::cout << running << '\n';
                }
            }
        }
        switch( e.type ){
            case SDL_KEYDOWN:
                switch(e.key.keysym.sym) {
                    case SDLK_SPACE: hard_drop = true; break;
                    case SDLK_LEFT: left = true; break;
                    case SDLK_RIGHT: right = true; break;
                    case SDLK_UP: up = true; break;
                    case SDLK_DOWN: down = true; break;
                    case SDLK_z: z = true; break;
                    case SDLK_x: x = true; break;
                    case SDLK_a: a = true; break;
                    case SDLK_c: c = true; break;
                }
                update();
        }
    }
}

void drawPiece(shape cur){
    drawBoard();
    draw_hold_shape();
    draw_next_piece();
    if(!running)
        return;
    return_to_menu = false;
    restart = false;
    for(int i=0; i < cur.size; i++) {
        for(int j=0; j < cur.size; j++) {
            if(cur.matrix[i][j]) {
                rect.x=100+(cur.x+i+4)*TILE_SIZE;
                rect.y=100+(cur.y+j-5)*TILE_SIZE;
                fill_matrix_board(rect.x, rect.y, num_piece+1);
                SDL_Rect pos = rect;
                pos.x -= 1; pos.y -= 1;
                pos.w = pos.h = 33;
                SDL_SetRenderDrawColor(getRenderer(), cur.color.r, cur.color.g, cur.color.b, 255);
                SDL_RenderFillRect(getRenderer(), &pos);
                SDL_SetRenderDrawColor(getRenderer(), 219, 219, 219, 255);
                SDL_RenderDrawRect(getRenderer(), &pos);
                prePos.push_back({rect.x, rect.y});
            }
        }
    }
    if(!check_collision_bottom(prePos)){
        running = false;
        used_hold = false;
        return;
    }
    else
        running = true;
    erasePre_matrix_board(prePos);
}

void renderPiece() {
    SDL_SetRenderDrawColor(getRenderer(), 0, 0, 0, 255);
    SDL_RenderClear(getRenderer());
    drop++;
    if(level < Max_level && cleared_line >= level+5){
        int tmp = cleared_line - (level+5);
        level++;
        cleared_line = tmp;
    }
    if(drop % speed[level] == 0){
        drop = 0;
        if(!hard_drop && check_collision_bottom(prePos))
            cur.y++;
    }
    drawPiece(cur);
    ghost_block(cur);
    int tmp = line_clear();
    cleared_line += tmp;
    total_line_cleared += tmp;
    score += (40+40*level)*tmp;
    display_block(blocks);
    // text around board
    loadText("Level", {255, 255, 255, 255}, {160, 500, 100, 50});
    loadText(std::to_string(level), {255, 255, 255, 255}, {180, 540, 50, 50});
    loadText("Lines", {255, 255, 255, 255}, {160, 580, 100, 50});
    loadText(std::to_string(cleared_line), {255, 255, 255, 255}, {180, 620, 50, 50});
    loadText("Score", {255, 255, 255, 255}, {640, 660, 100, 50});
    loadText(std::to_string(score), {255, 255, 255, 255}, {640, 700, std::to_string(score).size()*20+30, 50});
}


void runGame(int start_level){
    level = start_level;
    random_piece();
    cur = blocks[num_piece];
    rect.w = rect.h = TILE_SIZE;
    running = true;
    rotate_right();
    currentTime = SDL_GetTicks();
    lastTime = currentTime;
    while(running) {
//        currentTime = SDL_GetTicks();
//        delta = currentTime - lastTime;
        SDL_RenderPresent(getRenderer());
//        if(delta > 30){
//            std::cout << 0 << '\n';
//            lastTime = currentTime;
//        }
        check_move();
        prePos.clear();
        renderPiece();
    }
    score += 10*(level+1);
}

bool isQuit(){
    return quit_game;
}

int cur_level(){
    return level;
}

bool isReturnTOMenu(){
    return return_to_menu;
}

bool isRestart(){
    return restart;
}

int getScore(){
    return score;
}

void setScore(int num){
    score = num;
}

void setClearedLine(int num){
    cleared_line = num;
}
