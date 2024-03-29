#include "rotation.h"

bool running = true, left, right, up, down, z;

shape reverseCols(shape s) {
    shape tmp = s;
    for(int i=0; i<s.size; i++) {
        for(int j=0; j<s.size/2; j++) {
            bool t = s.matrix[i][j];
            tmp.matrix[i][j] = s.matrix[i][s.size-j-1];
            tmp.matrix[i][s.size-j-1] = t;
        }
    }
    return tmp;
}

shape transpose(shape s) {
    shape tmp = s;
    for(int i=0; i<s.size; i++) {
        for(int j=0; j<s.size; j++) {
            tmp.matrix[i][j] = s.matrix[j][i];
        }
    }
    return tmp;
}

void rotate_left(shape cur) {
    cur = reverseCols(transpose(cur));
}

void rotate_right(shape cur) {
    for(int i = 0; i < 3; i++)
        cur = reverseCols(transpose(cur));
}

void update(shape cur) {
    if(left) cur.x--;
    if(right) cur.x++;
    if(down) cur.y++;
    if(up) rotate_right(cur);
    if(z) rotate_left(cur);
}

void check_move(shape cur){
    up=down=left=right=z=0;
    SDL_Event e;
    while(SDL_PollEvent(&e) && e.key.repeat == 0) {
        if(e.type == SDL_QUIT) running=false;
        switch( e.type ){
            case SDL_KEYUP: //DOWN
                switch(e.key.keysym.sym) {
                    case SDLK_LEFT:
                        left=1;
                        break;
                    case SDLK_RIGHT:
                        right=1;
                        break;
                    case SDLK_UP:
                        up=1;
                        break;
                    case SDLK_DOWN:
                        down=1;
                        break;
                    case SDLK_z:
                        z = 1;
                        break;
                    case SDLK_ESCAPE:
                        running=false;
                        break;
                }
            update(cur);
        }
    }
}
