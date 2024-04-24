#ifndef GVAR_H
#define GVAR_H

#include <SDL.h>
#include <set>
#include <vector>
#include "block.h"

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
static int speed[5] = {30, 20, 15, 10, 8};

#endif // GVAR_H
