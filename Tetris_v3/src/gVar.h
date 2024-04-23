#ifndef GVAR_H
#define GVAR_H

#include <set>
#include <vector>
#include "block.h"

static shape blocks[7];

static shape cur, next, hold;
static bool isHold = false;
static int hold_piece_num = 0;

static bool running;
static int lastTime = 0;
static bool Game_over = false;

static int score = 0;
static int cleared_line = 0;

static std::set<int> seven_bag_system;
static std::vector<int> next_piece;
static int lv = 0;
static int speed[5] = {100, 80, 60, 40, 20};

#endif // GVAR_H
