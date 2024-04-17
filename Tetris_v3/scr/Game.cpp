#include "Game.h"

int frameCount, timerFPS, lastFrame, fps;
int num_piece = -1;
SDL_Rect rect;
std::vector<std::pair<int, int>> prePos;
//std::set<int> seven_bag_system;
bool left, right, up, down, z, x, a, hard_drop, c;
int drop = 0;
bool used_hold = false;

void initBlock(){
    make_block(blocks);
}

int random_piece(){
    num_piece = rand() % 7;
    if(seven_bag_system.size() == 7)
        seven_bag_system.clear();
    while(seven_bag_system.find(num_piece) != seven_bag_system.end())
        num_piece = rand() % 7;
    seven_bag_system.insert(num_piece);
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
    if(isHold)
        std::cout << "true\n";
    else
        std::cout << "false\n";
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
    //check piece
    for(int i=0; i<hold.size; i++){
        for(int j=0; j<hold.size; j++)
            std::cout << hold.matrix[i][j] << " ";
        std::cout << '\n';
    }
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
                SDL_RenderFillRect(getRenderer(), &pos);
                SDL_SetRenderDrawColor(getRenderer(), 219, 219, 219, 255);
                SDL_RenderDrawRect(getRenderer(), &pos);
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
//                SDL_RenderFillRect(getRenderer(), &rect);
//                SDL_SetRenderDrawColor(getRenderer(), 219, 219, 219, 255);
                SDL_RenderDrawRect(getRenderer(), &rect);
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
        if(e.type == SDL_QUIT){ running = false; Game_over = true;}
        switch( e.type ){
            case SDL_KEYDOWN:
                switch(e.key.keysym.sym) {
                    case SDLK_SPACE: hard_drop = 1; break;
                    case SDLK_LEFT: left = 1; break;
                    case SDLK_RIGHT: right = 1; break;
                    case SDLK_UP: up = 1; break;
                    case SDLK_DOWN: down = 1; break;
                    case SDLK_z: z = 1; break;
                    case SDLK_x: x = 1; break;
                    case SDLK_a: a = 1; break;
                    case SDLK_c: c = 1; break;
                    case SDLK_ESCAPE: running = false; break;
                }
                update();
        }
    }
}

void drawPiece(shape cur){
    drawBoard();
    if(!running)
        return;
    for(int i=0; i < cur.size; i++) {
        for(int j=0; j < cur.size; j++) {
            if(cur.matrix[i][j]) {
                rect.x=100+(cur.x+i+4)*TILE_SIZE;
                rect.y=100+(cur.y+j-5)*TILE_SIZE;
                fill_matrix_board(rect.x, rect.y, num_piece+1);
                SDL_SetRenderDrawColor(getRenderer(), cur.color.r, cur.color.g, cur.color.b, 255);
                SDL_RenderFillRect(getRenderer(), &rect);
                SDL_SetRenderDrawColor(getRenderer(), 219, 219, 219, 255);
                SDL_RenderDrawRect(getRenderer(), &rect);
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
//    std::cout << drop;
    frameCount++;
    int timerFPS = SDL_GetTicks()-lastFrame;
    if(timerFPS<(1000/60)) {
//        drop++;
//        if(lv < 4 && cleared_line >= 4){
//            int tmp = cleared_line - 4;
//            lv++;
//            cleared_line = tmp;
//        }
//        if(drop % speed[lv] == 0){
//            drop = 0;
//            cur.y++;
//            std::cout << "\033[2J\033[1;1H";
//            std::cout << "number of line cleared: " << cleared_line << '\n';
//            std::cout << "level: " << lv << '\n';
//        }
        SDL_Delay((1000/60)-timerFPS);
    }
    draw_hold_shape();
    drawPiece(cur);
    ghost_block(cur);
    cleared_line += line_clear();
    display_block(blocks);
}

void runGame(){
    random_piece();
//    std::cout << num_piece << std::endl;
    cur = blocks[num_piece];
    rect.w = rect.h = TILE_SIZE;
    running = true;
    rotate_right();
    while(running) {
        lastFrame = SDL_GetTicks();
        SDL_RenderPresent(getRenderer());
//        SDL_Delay(500);
        if(lastFrame>=(lastTime+3000)) {
            lastTime=lastFrame;
            fps=frameCount;
            frameCount=0;
        }
        check_move();
        prePos.clear();
//        if(c) return;
        renderPiece();
    }
}
