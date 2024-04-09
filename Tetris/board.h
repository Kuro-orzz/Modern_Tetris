#ifndef BOARD_H
#define BOARD_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <utility>
#include "init.h"

void loadBoard();
void drawBoard();
void showBoard();
void fill_matrix_board(int x, int y, int num);
void erasePre_matrix_board(std::vector<std::pair<int, int>> pre);
bool check_collision_bottom(std::vector<std::pair<int, int>> pre);
bool check_collision_left(std::vector<std::pair<int, int>> pre);
bool check_collision_right(std::vector<std::pair<int, int>> pre);

#endif // INIT_H
