#ifndef GVAR_H
#define GVAR_H

#include "block.h"

static shape blocks[7];
static shape cur, next;
static bool running;
static int lastTime = 0;
static bool Game_over = false;

shape getBlock(int num);

#endif // GVAR_H
