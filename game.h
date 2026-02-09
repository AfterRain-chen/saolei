#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 5
#define COL 5
#define ROWS (ROW+2)
#define COLS (COL+2)
#define EASY_COUNT 3

void initboard(char board [][COLS], int rows, int cols, char set);
void printboard(const char board[][COLS], int row, int col);
void setboard(char board[][COLS], int row, int col);


#endif