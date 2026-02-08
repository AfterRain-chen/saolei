#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#define ROW 11
#define COL 11
#define ROWS (ROW+2)
#define COLS (COL+2)

void initboard(char board [][COLS], int rows, int cols, char set);
void printboard(const char board[][COLS], int rows, int cols);

#endif