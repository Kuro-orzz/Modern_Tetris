#ifndef GVAR_H
#define GVAR_H

#include <set>
#include "block.h"

static shape blocks[7];
static shape cur, next;//, hold;
//static bool isHold = false;
static bool running;
static int lastTime = 0;
static bool Game_over = false;
static int score = 0;
static std::set<int> seven_bag_system;
//shape getBlock(int num);

#endif // GVAR_H
