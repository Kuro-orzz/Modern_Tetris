#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <vector>
#include <utility>
#include "block.h"
#include "board.h"
#include "init.h"
#include "gVar.h"
#define TILE_SIZE 35

void initBlock();

shape reverse_shape(shape s);
shape transpose(shape s);
void rotate_left();
void rotate_right();
void rotate_180();
void move();
void check_move();

void drawPiece(shape s);
void renderPiece();
void runGame();

#endif // GAME_H
