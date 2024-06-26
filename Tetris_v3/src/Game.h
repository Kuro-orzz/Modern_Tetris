#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <vector>
#include <utility>
#include <set>
#include "board.h"
#include "init.h"
#include "gVar.h"
#include "rotation.h"
#define TILE_SIZE 35

void initBlock();
int random_piece();

shape reverse_shape(shape s);
shape transpose(shape s);
void rotate_left();
void rotate_right();
void rotate_180();
void hold_shape();
void draw_hold_shape();
void draw_next_piece();
int hardDrop(std::vector<std::pair<int, int>> &pre);
void ghost_block(shape s);
void check_move();

void drawPiece(shape s);
void renderPiece();
void runGame(int start_level);
bool isQuit();
int cur_level();
bool isReturnTOMenu();
bool isRestart();
int getScore();
void setScore(int num);
void setClearedLine(int num);
void settingForNewGame();

#endif // GAME_H
