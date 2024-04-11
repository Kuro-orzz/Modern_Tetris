#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <vector>
#include <utility>
#include "board.h"
#include "init.h"
#include "gVar.h"
#include "rotation.h"
#include "collision.h"
#define TILE_SIZE 35

void initBlock();

shape reverse_shape(shape s);
shape transpose(shape s);
void rotate_left();
void rotate_right();
void rotate_180();
int hardDrop(std::vector<std::pair<int, int>> &pre);
void check_move();

void drawPiece(shape s);
void renderPiece();
void runGame();

#endif // GAME_H
