#ifndef GVAR_H
#define GVAR_H

#include <SDL.h>
#include <set>
#include <vector>
#include "block.h"

#define Max_level 20

static shape blocks[7];

static shape cur, next, hold;
static bool isHold = false;
static int hold_piece_num = 0;

static bool running;
static bool Game_over = false;

static int score = 0;
static int cleared_line = 0;
static int total_line_cleared = 0;

static std::set<int> seven_bag_system;
static std::vector<int> next_piece;
static int level = 0;
static int speed[21] = {70, 66, 60, 56, 52, 48, 44, 40, 36, 32, 28, 24, 22, 20, 18, 16, 14, 12, 10, 6, 4};

static bool return_to_menu = false;
static bool restart = false;
static bool go_back = false;

#endif // GVAR_H
