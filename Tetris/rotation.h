#ifndef ROTATION_H
#define ROTATION_H

#include "piece.h"

shape reverseCols(shape s);
shape transpose(shape s);
void rotate_left(shape cur);
void rotate_right(shape cur);
void update(shape cur);
void check_move(shape cur);

#endif // ROTATION_H
